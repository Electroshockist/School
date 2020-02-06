#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif //WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <WinSock2.h>
#include <iphlpapi.h>
#include <WS2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_PORT "27015"
#define DEFAULT_BUFFER_LENGTH 4096

bool CompareChar(const char* one, const char* two){
	std::string s1(one), s2(two);
	return s1 != s2;
}

int main(){
	std::string userData;

	WSAData wsaData;

	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;

	int iResult;
	int iSendResult;

	struct addrinfo
		*result = NULL,
		*ptr = NULL,
		hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if(iResult != 0){
		printf("getaddrinfo failed with result: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);

	if(iResult != 0){
		printf("error with result: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if(ListenSocket == INVALID_SOCKET){
		printf("Socket failed with code: %d", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if(ListenSocket == SOCKET_ERROR){
		printf("Bind failed with code: %d", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);

	if(listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR){
		printf("Listen failed with code: %d", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	ClientSocket = accept(ListenSocket, NULL, NULL);
	if(ClientSocket == INVALID_SOCKET){
		printf("Accept failed with code: %d", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	closesocket(ListenSocket);

	do{
		userData.clear();
		std::vector<char> buffer(DEFAULT_BUFFER_LENGTH);
		iResult = recv(ClientSocket, &buffer[0], buffer.size(), 0);

		if(iResult > 0){
			printf("Bytes recieved: %d\n", iResult);
			iSendResult = send(ClientSocket, &buffer[0], iResult, 0);
			if(iSendResult == SOCKET_ERROR){
				printf("Send failed with code: %d\n", WSAGetLastError());
				closesocket(ListenSocket);
				WSACleanup();
				return 1;
			}
			userData.append(buffer.cbegin(), buffer.cend());
			std::cout << "Text Received: " << userData.c_str() << std::endl;
			printf("Bytes sent: %d\n", iSendResult);

		} else if(iResult < 0){
			printf("recv failed with error: %d\n", WSAGetLastError());
			closesocket(ClientSocket);
			WSACleanup();
			return 1;
		}
	} while(CompareChar(userData.c_str(), "exit"));

	iResult = shutdown(ClientSocket, SD_SEND);
	if(iResult == SOCKET_ERROR){
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		return 1;
	}

	printf("Connection closed...\n");

	closesocket(ClientSocket);
	WSACleanup();

	return 0;
}