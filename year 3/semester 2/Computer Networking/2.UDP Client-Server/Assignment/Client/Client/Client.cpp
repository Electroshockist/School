#include <vector>
#include <string>
#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib,  "ws2_32.lib")

#define EXITSYMBOL "exit"
#define SENDSYMBOL "send"

const std::string WHITESPACE = " \n\r\t\f\v";

bool charsEqual(const char *one, const char *two){
	std::string a(one), b(two);

	return a == b;
}
//credit to: https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
std::string cleanString(std::string string){
	size_t start = string.find_first_not_of(WHITESPACE);
	size_t end = string.find_last_not_of(WHITESPACE);

	return (start == std::string::npos || end == std::string::npos) ? "" : string.substr(start, end);
}

std::vector<std::string> getInput(bool *doExit){
	std::vector<std::string> inputVector;
	std::string input;
	do{
		input.clear();
		std::getline(std::cin, input);
		if(!charsEqual(input.c_str(), SENDSYMBOL) || !input.empty()){
			inputVector.push_back(input.c_str());
		}

	} while(charsEqual(input.c_str(), EXITSYMBOL) && charsEqual(input.c_str(), SENDSYMBOL));

	*doExit = charsEqual(input.c_str(), EXITSYMBOL);
	return inputVector;
}

int main(){
	WSAData data;
	WORD version = MAKEWORD(2, 2);
	int wsOK = WSAStartup(version, &data);

	bool exit = false;

	if(wsOK != 0){
		std::cout << "Couldn't start winsock: " << wsOK << std::endl;
		return -1;
	}

	SOCKET sckt = socket(AF_INET, SOCK_DGRAM, 0);

	//Server-Client specific code
	sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(54000);
	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

	std::vector<std::string> s;
	do{
		s = getInput(&exit);
		if(!s.empty()){
			int sendOK = sendto(sckt, s.c_str(), s.size() + 1, 0, (sockaddr *)&server, sizeof(server));
			if(sendOK == SOCKET_ERROR){
				std::cout << "Failed to send: " << WSAGetLastError() << std::endl;
				return -1;
			}
		}
	} while(!exit);

	closesocket(sckt);
	WSACleanup();
}