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

#include "IData.h"

#pragma comment(lib, "Ws2_32.lib")

#define DEFAULT_PORT "27015"
class Network{
	WSADATA wsaData;
	int iResult, iSendResult;

	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;

	struct addrinfo *result = NULL;
	struct addrinfo hints;

public:
	int Connect();

	int Send(IData data);
};
