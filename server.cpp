#include <cstdio>  
#include <iostream>  
#include <string>  
#include <winsock2.h>  
#pragma comment(lib,"ws2_32.lib")  
using namespace std;  
const int PORT = 8009;  
int main()  
{  
	int n;  
	WSADATA wd;  
	n=WSAStartup(MAKEWORD(2, 2), &wd);  
	if (n)  
	{  
		cout << "WSAStartup��������" << endl;  
		return -1;  
	}  
	SOCKET sock = socket(AF_INET, SOCK_DGRAM,0);  
	if (INVALID_SOCKET == sock)  
	{  
		cout << "socket����ʧ��!" << endl;  
		cout << "�������ǣ�" << WSAGetLastError() << endl;  //���ش������
		return -1;  
	}  
	sockaddr_in sa = { AF_INET, htons(PORT) };  
	n=bind(sock,(sockaddr*)&sa, sizeof(sa));  
	if (n == SOCKET_ERROR)  
	{  
		cout << "bind�󶨶˿�ʧ�ܣ�" << endl;  
		cout << "�������ǣ�" << WSAGetLastError() << endl;  //���ش������
		return -1;  
	}  
	else  
	{  
		cout << "�˿ڷ����ɹ�:" << PORT << endl;  
	}  
	char s[256];  
	while (true)  
	{  
		n = recv(sock, s, sizeof(s), 0); //recv���ص���ʵ��copy���ֽ���  
		s[n] = '\0';  
		cout << s << endl;  
	}  

	return 0;  

}  