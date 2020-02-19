#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include "Sample.h"

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"

int main(){
	WSADATA wsaData;
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;
	char recvbuf[sizeof(Sample)];
	int iResult;

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if(iResult != 0){
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	iResult = getaddrinfo("localhost", DEFAULT_PORT, &hints, &result);
	if(iResult != 0){
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	for(ptr = result; ptr != NULL; ptr = ptr->ai_next){
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if(ConnectSocket == INVALID_SOCKET){
			printf("Socket failed with error: %d\n", WSAGetLastError());
			WSACleanup();
			return 1;
		}

		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if(iResult == SOCKET_ERROR){
			printf("connect failed with error: %d\n", iResult);
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}
		break;
	}
	freeaddrinfo(result);

	if(ConnectSocket == INVALID_SOCKET){
		printf("Unable to connect to server\n");
		WSACleanup();
		return 1;
	}

	//message
	Sample msg;
	msg.A = 123;
	msg.B = 457;
	char *tmp = reinterpret_cast<char *>(&msg);

	iResult = send(ConnectSocket, tmp, sizeof(Sample), 0);
	if(iResult == SOCKET_ERROR){
		printf("send failed with result: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	printf("Bytes sent: %d\n", iResult);

	iResult = shutdown(ConnectSocket, SD_SEND);
	if(iResult == SOCKET_ERROR){
		printf("shutdown failed with result: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	do{
		iResult = recv(ConnectSocket, recvbuf, sizeof(Sample), 0);
		if(iResult > 0){
			printf("Bytes recieved: %d\n", iResult);

			Sample *response = reinterpret_cast<Sample *>(recvbuf);
			msg = Sample(*response);

			std::cout << "A: " << std::to_string(msg.A) << std::endl;
			std::cout << "B: " << std::to_string(msg.B) << std::endl;
		} else if(iResult == 0){
			printf("Connection closing...");
		} else{
			printf("Recieve failed with error: %d\n", WSAGetLastError());
		}
	} while(iResult > 0);
	// cleanup
	closesocket(ConnectSocket);
	WSACleanup();

	return 0;
}