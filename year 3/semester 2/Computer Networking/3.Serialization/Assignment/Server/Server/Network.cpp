#include "Network.h"

int Network::Connect(){
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if(iResult != 0){
		printf("WSAStartup failed with error: %d\n", iResult);
		return 1;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if(iResult != 0){
		printf("getaddrinfo failed with error: %d\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if(ListenSocket == INVALID_SOCKET){
		printf("socket failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return 1;
	}

	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if(iResult == SOCKET_ERROR){
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if(iResult == SOCKET_ERROR){
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}

	printf("Awaiting connection...");

	ClientSocket = accept(ListenSocket, NULL, NULL);
	if(ClientSocket == INVALID_SOCKET){
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	closesocket(ListenSocket);
	return 0;
}

int Network::Send(IData data){
	char recvbuf[sizeof(data)];

	do{
		iResult = recv(ClientSocket, recvbuf, sizeof(data), 0);
		if(iResult > 0){
			printf("Bytes recieved: %d\n", iResult);

			IData *msg = reinterpret_cast<IData *>(recvbuf);

			iSendResult = send(ClientSocket, recvbuf, sizeof(IData), 0);
			if(iSendResult == SOCKET_ERROR){
				printf("send failed with result: %d\n", iSendResult);
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}

			printf("Bytes sent: %d\n", iSendResult);
		} else if(iResult == 0){
			printf("Connection closing...");
		} else{
			printf("recieve failed with error: %d\n", WSAGetLastError());
			closesocket(ClientSocket);
			WSACleanup();
			return 1;
		}
	} while(iResult > 0);

	iResult = shutdown(ClientSocket, SD_SEND);
	if(iResult == SOCKET_ERROR){
		printf("recieve failed with error: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		return 1;
	}

	closesocket(ClientSocket);
	WSACleanup();
	return 0;
}
