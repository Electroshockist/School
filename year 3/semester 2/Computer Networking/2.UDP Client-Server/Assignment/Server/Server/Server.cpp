#include <iostream>
#include <WS2tcpip.h>
#include <algorithm>

#pragma comment (lib,  "ws2_32.lib")

#define EXITSYMBOL "exit"
const std::string WHITESPACE = " \n\r\t\f\v";

bool charsEqual(const char *one, const char *two){
	std::string a(one), b(two);

	return a == b;
}

//credit to: https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
std::string cleanString(std::string string){
	size_t start = string.find_first_not_of(WHITESPACE);
	size_t end = string.find_last_not_of(WHITESPACE);

	return (start == std::string::npos || end == std::string::npos) ? "" : string.substr(start, end + 1);
}

std::string parseString(std::string string){
	size_t place = string.find_first_of("|", 0);
	std::string s = string.substr(0, place).append("|");;
	std::cout << s.c_str() << std::endl;
	return s;
}

int main(){
	WSAData data;
	WORD version = MAKEWORD(2, 2);
	int wsOK = WSAStartup(version, &data);

	bool doExit = false;

	if(wsOK != 0){
		std::cout << "Couldn't start winsock: " << wsOK << std::endl;
		return -1;
	}

	SOCKET sckt = socket(AF_INET, SOCK_DGRAM, 0);

	//Server-Client specific code
	sockaddr_in serverHint;
	serverHint.sin_addr.S_un.S_addr = ADDR_ANY;
	serverHint.sin_family = AF_INET;
	serverHint.sin_port = htons(54000);
	inet_pton(AF_INET, "127.0.0.1", &serverHint.sin_addr);

	if(bind(sckt, (sockaddr *)&serverHint, sizeof(serverHint)) == SOCKET_ERROR){
		std::cout << "Socket bind failed: " << WSAGetLastError() << std::endl;
		return -1;
	}

	sockaddr_in client;
	int clientLength = sizeof(client);

	char buf[1024];
	do{
		ZeroMemory(&client, clientLength);
		ZeroMemory(buf, 1024);

		int bytesIn = recvfrom(sckt, buf, 1024, 0, (sockaddr *)&client, &clientLength);
		if(bytesIn == SOCKET_ERROR){
			std::cout << "Error receiving from the client " << WSAGetLastError() << std::endl;
			continue;
		}
		doExit = charsEqual(cleanString(std::string(buf)).c_str(), EXITSYMBOL);

		char clientIP[256];

		ZeroMemory(clientIP, 256);

		inet_ntop(AF_INET, &client.sin_addr, clientIP, 256);
		if(!doExit){
			// Display the message / who sent it
			parseString(std::string(buf));
			//std::cout << "Message recv from " << clientIP << " : " << buf << std::endl;
		}

		int bytesOut = sendto(sckt, buf, sizeof(buf), 0, (sockaddr *)&client, sizeof(client));
		if(bytesOut == SOCKET_ERROR){
			std::cout << "Error sending to the client " << WSAGetLastError() << std::endl;
			continue;
		}
	} while(!doExit);

	closesocket(sckt);
	WSACleanup();
}