#include <iostream>
#include <WS2tcpip.h>

#pragma comment (lib,  "ws2_32.lib")

int main(){
	WSAData data;
	WORD version = MAKEWORD(2, 2);
	int wsOK = WSAStartup(version, &data);

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

	if(bind(sckt, (sockaddr *)&serverHint, sizeof(serverHint)) == SOCKET_ERROR){
		std::cout << "Socket bind failed: " << WSAGetLastError() << std::endl;
		return -1;
	}

	sockaddr_in client;
	int clientLength = sizeof(client);

	char buf[1024];
	while(true){
		ZeroMemory(&client, clientLength);
		ZeroMemory(buf, 1024);

		int bytesIn = recvfrom(sckt, buf, 1024, 0, (sockaddr *)&client, &clientLength);
		if(bytesIn == SOCKET_ERROR){
			std::cout << "Error recieving from the client " << WSAGetLastError() << std::endl;
			continue;
		}
		char clientIP[256];

		ZeroMemory(clientIP, 256);

		inet_ntop(AF_INET, &client.sin_addr, clientIP, 256);

		// Display the message / who sent it
		std::cout << "Message recv from " << clientIP << " : " << buf << std::endl;
	}

	closesocket(sckt);
	WSACleanup();
}