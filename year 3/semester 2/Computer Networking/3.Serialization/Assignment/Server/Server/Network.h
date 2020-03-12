#pragma once
#undef UNICODE
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
class Network{
	WSADATA wsaData;
	int iResult, iSendResult;

	SOCKET ClientSocket = INVALID_SOCKET;
	SOCKET ConnectSocket = INVALID_SOCKET;

	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;

	int ConnectToSend();
	int ConnectToRecieve();

public:
	int Connect();

	int Send(const Sample data);

	int Recieve(Sample& data);

	int Shutdown();

	~Network(){
		Shutdown();
	}
};

