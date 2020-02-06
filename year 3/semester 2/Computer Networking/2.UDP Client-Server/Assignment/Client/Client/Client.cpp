#include <string>
#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib,  "ws2_32.lib")

bool charsNotEqual(const char *one, const char *two){
	std::string a(one), b(two);

	return a != b;
}


std::string getInput(bool *doExit){
	std::string cattedInput = "";
	std::string input;
	do{
		cattedInput.append(input.c_str());
		if(!input.empty()){
			cattedInput.append("\n");
		}

		input.clear();
		//cin is after concatinating the input, because we do not want to send the words "send" or "exit", as they are commands
		std::getline(std::cin, input);

		//std::cout << "input: \"" << input << "\" == \"exit\": " << (charsNotEqual(input.c_str(), "exit") ? "true" : "false") << std::endl;

	} while(charsNotEqual(input.c_str(), "exit") && charsNotEqual(input.c_str(), "send"));

	*doExit = !charsNotEqual(input.c_str(), "exit");
	return cattedInput;
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

	std::string s;
	do{
		if(!s.empty()){
			int sendOK = sendto(sckt, s.c_str(), s.size() + 1, 0, (sockaddr *)&server, sizeof(server));
			if(sendOK == SOCKET_ERROR){
				std::cout << "Failed to send: " << WSAGetLastError() << std::endl;
				return -1;
			}
		}
		s = getInput(&exit);
	} while(!exit);

	closesocket(sckt);
	WSACleanup();
}