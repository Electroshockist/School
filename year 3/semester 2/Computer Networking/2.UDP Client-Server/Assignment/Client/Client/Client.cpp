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

std::vector<std::string> getInput(bool &doExit, bool needResponse){
	std::vector<std::string> inputVector;
	std::string input;

	bool doSend = false;
	do{
		input.clear();
		std::getline(std::cin, input);
		//check if "exit" was typed
		doExit = charsEqual(input.c_str(), EXITSYMBOL);
		//check if "send" was typed
		doSend = charsEqual(input.c_str(), SENDSYMBOL);

		//if we need to wait for a response, check if "exit" was recieved, then return
		if(needResponse){
			if(doSend){
				printf("Cannot send: awaiting server response");
			}

			if(doExit){
				inputVector.push_back(input);
			}

			return inputVector;
		}
		//if current line is not empty and is not equal to "send", add current line to input list
		if(!doSend && !input.empty()){
			inputVector.push_back(input.c_str());
		}
	}
	//keep getting input unless "send" or "exit" was typed
	while(!doSend && !doExit);

	return inputVector;
}

bool sendStrings(SOCKET &sckt, sockaddr_in &server, std::vector<std::string> strings, int &size){
	size = 0;
	for(size_t i = 0; i < strings.size(); i++){
		std::string s = std::to_string(i) + "|" + strings[i];
		int sendOK = sendto(sckt, s.c_str(), s.size() + 1, 0, (sockaddr *)&server, sizeof(server));
		if(sendOK == SOCKET_ERROR){
			std::cout << "Failed to send: " << WSAGetLastError() << std::endl;
			return false;
		}
		size += s.size();
	}
	return true;
}

bool getResponse(SOCKET sckt, int lastMessageSize){ 
	sockaddr_in server;
	int serverLength = sizeof(server);
	char buf[1024];

	ZeroMemory(&server, serverLength);
	ZeroMemory(buf, 1024);

	int bytesIn = recvfrom(sckt, buf, 1024, 0, (sockaddr *)&server, &serverLength);
	if(bytesIn == SOCKET_ERROR){
		std::cout << "Error receiving from the client " << WSAGetLastError() << std::endl;
	}
	return std::string(buf).size() == lastMessageSize;
}

int main(){
	WSAData data;
	WORD version = MAKEWORD(2, 2);
	int wsOK = WSAStartup(version, &data);

	bool exit = false, needResponse = false;

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

	do{
		int lastMessageSize = -1;
		if(!sendStrings(sckt, server, getInput(exit, needResponse), lastMessageSize)) return -1;

		printf("Awaiting response...\n");

		//save if response is correct
		needResponse = !getResponse(sckt, lastMessageSize);
		printf("Response recieved\n");

	} while(!exit);

	closesocket(sckt);
	WSACleanup();
}