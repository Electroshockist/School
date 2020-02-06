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
	sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(54000);
	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

	std::string s("Hello there");

	int sendOK = sendto(sckt, s.c_str(), s.size() + 1, 0, (sockaddr *)&server, sizeof(server));
	if(sendOK == SOCKET_ERROR){
		std::cout << "Failed to send: " << WSAGetLastError() << std::endl;
		return -1;
	}

	closesocket(sckt);
	WSACleanup();
}