#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif //WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <WinSock2.h>
#include <iphlpapi.h>
#include <WS2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_PORT "27015"
#define DEFAULT_BUFFER_LENGTH 512
#define DEFAULT_HOST "localhost"

int main(){
	WSADATA wsaData;

	struct addrinfo
		*result = NULL,
		*ptr = NULL,
		hints;

	int iResult;

	char sendbuf[] = "hello server!";
	char recvbuf[DEFAULT_BUFFER_LENGTH];
	int recvbuflen = DEFAULT_BUFFER_LENGTH;

	SOCKET ConnectSocket = INVALID_SOCKET;

	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if(iResult != 0){
		printf("error with result: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	iResult = getaddrinfo(DEFAULT_HOST, DEFAULT_PORT, &hints, &result);

	if(iResult != 0){
		printf("getaddrinfo failed with result: %d\n", iResult);
		WSACleanup();
		return 1;
	}

	for(ptr = result; ptr != NULL; ptr = ptr->ai_next){
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

		if(ConnectSocket == INVALID_SOCKET){
			printf("Socket failed with result: %d\n", iResult);
			WSACleanup();
			return 1;
		}

		iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
		if(iResult == SOCKET_ERROR){
			closesocket(ConnectSocket);
			ConnectSocket = INVALID_SOCKET;
			continue;
		}

	}

	freeaddrinfo(result);
	if(ConnectSocket == INVALID_SOCKET){
		printf("Unable to connect to server");
		WSACleanup();
		return 1;
	}

	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	if(iResult == SOCKET_ERROR){
		printf("Send failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	printf("Bytes Sent: %ld\n", iResult);

	// shutdown the connection since no more data will be sent
	iResult = shutdown(ConnectSocket, SD_SEND);
	if(iResult == SOCKET_ERROR){
		printf("shutdown failed with error: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}

	do{
		iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
		if(iResult > 0){
			printf("Bytes recieved: %d\n", iResult);
		} else if(iResult == 0){
			printf("Connection closed...\n");
		} else
			printf("recv failed with code: %d\n", WSAGetLastError());

	} while(iResult > 0);
	closesocket(ConnectSocket);
	WSACleanup();

	return 0;
}