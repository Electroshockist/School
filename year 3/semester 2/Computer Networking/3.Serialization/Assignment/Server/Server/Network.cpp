#include "Network.h"

int Network::ConnectToSend(){
	for(ptr = result; ptr != NULL; ptr = ptr->ai_next){
		ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
		if(ConnectSocket == INVALID_SOCKET){
			printf("Socket failed with error: %d\n", WSAGetLastError());
			WSACleanup();
			return EXIT_FAILURE;
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
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int Network::ConnectToRecieve(){
	SOCKET ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if(ListenSocket == INVALID_SOCKET){
		printf("socket failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return EXIT_FAILURE;
	}

	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if(iResult == SOCKET_ERROR){
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		return EXIT_FAILURE;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if(iResult == SOCKET_ERROR){
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return EXIT_FAILURE;
	}

	printf("Awaiting connection...");

	ClientSocket = accept(ListenSocket, NULL, NULL);
	if(ClientSocket == INVALID_SOCKET){
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return EXIT_FAILURE;
	}
	closesocket(ListenSocket);
	return EXIT_SUCCESS;
}

int Network::Connect(){
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if(iResult != 0){
		printf("WSAStartup failed with error: %d\n", iResult);
		return EXIT_FAILURE;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	iResult = getaddrinfo("localhost", DEFAULT_PORT, &hints, &result);
	if(iResult != 0){
		printf("getaddrinfo failed with error: %d\n", WSAGetLastError());
		WSACleanup();
		return EXIT_FAILURE;
	}

	if(ConnectToRecieve() != EXIT_SUCCESS){
		return EXIT_FAILURE;
	}


	return EXIT_SUCCESS;
}

int Network::Send(Sample data){
	char recvbuf[sizeof(Sample)];
	//message
	char *tmp = reinterpret_cast<char *>(&data);

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

	// cleanup
	closesocket(ConnectSocket);
	WSACleanup();
	return 0;
}

int Network::Recieve(Sample &data){
	char recvbuf[sizeof(Sample)];

	iResult = recv(ClientSocket, recvbuf, sizeof(data), 0);
	if(iResult > 0){
		printf("Bytes recieved: %d\n", iResult);

		Sample *msg = reinterpret_cast<Sample *>(recvbuf);

		iSendResult = send(ClientSocket, recvbuf, sizeof(Sample), 0);
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

	return 0;
}

int Network::Shutdown(){
	iResult = shutdown(ClientSocket, SD_SEND);
	if(iResult == SOCKET_ERROR){
		printf("failed to shutdown with with error: %d\n", WSAGetLastError());
		closesocket(ClientSocket);
		WSACleanup();
		return 1;
	}

	closesocket(ClientSocket);
	WSACleanup();
	return 0;
}
