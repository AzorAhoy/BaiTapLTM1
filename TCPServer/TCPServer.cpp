// TCPServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*. Viết chương trình TCPServer, đợi kết nối ở cổng xác định bởi tham số dòng lệnh. 
	Mỗi khi có client kết nối đến, thì gửi xâu chào được chỉ ra trong một tệp tin xác định, 
	sau đó ghi toàn bộ nội dung client gửi đến vào một tệp tin khác được chỉ ra trong tham số 
	dòng lệnh TCPServer.exe VD: TCPServer.exe 8888 chao.txt client.txt*/


#include "pch.h"
#include <iostream>
#include "winsock2.h"
#include <fstream>
using namespace std;
#define _WINSOCK_DEPRECATED_NO_WARNINGS
using namespace std;

char *hello(char *filePaths) {
	FILE *f;
	f = fopen(filePaths, "r");
	char *helloString = new char[50];
	fgets(helloString, 255, (FILE*)f);
	fclose(f);
	return helloString;
}

void saveMsg(char *mgs, char *filePath) {
	FILE *f;
	f = fopen(filePath, "w");
	fputs(mgs, f);
	fclose(f);
}


int main(int argc, char * argv[])
{

	char port = *(argv[0]);

	WSADATA wsaData;
	//Khoi tao WinSock 2.2
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	//Tao socket nghe ket noi tu Client
	SOCKET ListeningSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN ServerAddr;

	//Khoi tao cau truc SOCKADDR_IN cua server
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	ServerAddr.sin_port = htons(port);
	
	//Bind socket cua server
	bind(ListeningSocket, (SOCKADDR *)&ServerAddr, sizeof(ServerAddr));
	//Chuyen sang trang thai doi ket noi
	listen(ListeningSocket, 5);
	//Chap nhan ket noi moi
	SOCKET NewConnection = accept(ListeningSocket, NULL, NULL);
	//Sau khi chap nhan ket noi moi, server co the tiep tuc chap nhan
	//them cac ket noi khac, hoac gui nhan du lieu voi cac client
	//thong qua cac socket duoc accept voi client
	char buf[1024];
	int ret;

	char * filename = argv[2];
	//std::cout << argv[2];
	//send(NewConnection, hello(argv[2]), strlen(hello(argv[2])), 0);
	std::ifstream f(filename);

	if (f.is_open())
		std::cout << f.rdbuf();

	fstream file;
	char* filename2 = argv[3];
	file.open(filename2, ios::out | ios::binary);

	while (true)
	{
		ret = recv(NewConnection, buf, sizeof(buf), 0);
		if (ret <= 0)
			break;

		buf[ret] = 0;

		file << buf << "\r\n";
		//saveMsg(buf, argv[3]);
		printf("Received: %s\n", buf);
	}
	file.close();
	//Dong socket
	closesocket(NewConnection);
	closesocket(ListeningSocket);
	//Giai phong WinSock
	WSACleanup();
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
