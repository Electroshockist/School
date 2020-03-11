#pragma once
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
	SOCKET ConnectSocket = INVALID_SOCKET;
	struct addrinfo *result = NULL,
		*ptr = NULL,
		hints;
	char recvbuf[sizeof(Sample)];
	int iResult;

public:

	int Connect();

	int Recieve();
};

