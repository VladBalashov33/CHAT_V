// ============================CLIENT============================
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <windows.h>
#include <conio.h>
#pragma comment(lib,"Ws2_32.lib") 
#define PORT 666
#define SERVERADDR "127.0.0.1" 
#define BUFF 1024

DWORD WINAPI Recovering(LPVOID client_socket);

int main(int argc, char* argv[])
{
    char Wbuff[1024];
    printf("============================CLIENT============================\n");
 
    if (WSAStartup(0x202, (WSADATA *)&Wbuff[0]))
    {
        printf("WSAStart error %d\n", WSAGetLastError());
        return -1;
    }
 
    SOCKET my_sock;
    my_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (my_sock < 0)
    {
        printf("Socket() error %d\n", WSAGetLastError());
        return -1;
    }
 
    sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(PORT);
    HOSTENT *hst;
 
    if (inet_addr(SERVERADDR) != INADDR_NONE)
	{
        dest_addr.sin_addr.s_addr = inet_addr(SERVERADDR);
	}
    else
    {
        if (hst = gethostbyname(SERVERADDR))
		{														
            ((unsigned long *)&dest_addr.sin_addr)[0] = ((unsigned long **)hst->h_addr_list)[0][0];
		}
        else
        {
            printf("Invalid address %s\n", SERVERADDR);
            closesocket(my_sock);
			getch();
            WSACleanup();
            return -1;
        }
    }

    if (connect(my_sock, (sockaddr *)&dest_addr, sizeof(dest_addr)))
    {
        printf("Connect error %d\n", WSAGetLastError());
		getch();
        return -1;
    }
 
    printf("Connection with %s complite\nType qqq for quit\n\n", SERVERADDR);

	char name[32];
	printf("Enter the name:\n");
	scanf("%s",&name);
	printf("Your name is: %s\n", name);
	strcat(name,":");
	
	DWORD thID;
	CreateThread(NULL, NULL, Recovering, &my_sock, NULL, &thID);
    while (1)
    {
		char buff[BUFF];							
		fgets(&buff[0], sizeof(buff)- 1, stdin);

		if (!strcmp(&buff[0], "qqq\n"))
		{
			printf("Exit...");
			closesocket(my_sock);
			WSACleanup();
			getch();
			return 0;
		}
		send(my_sock, &name[0], strlen(&name[0]), 0);
		send(my_sock, &buff[0], strlen(&buff[0]), 0);			
    }
    printf("Recv error %d\n", WSAGetLastError());
    closesocket(my_sock);
    WSACleanup();
    return -1;
}

DWORD WINAPI Recovering(LPVOID client_socket)
{ 
	int nsize;
	SOCKET my_sock;
    my_sock = ((SOCKET *)client_socket)[0];
	char buff[BUFF];
	while (1)
	{
		nsize = recv(my_sock, &buff[0], sizeof(buff) - 1, 0);
		if (nsize != SOCKET_ERROR)
		{
			buff[nsize] = 0;	
			printf("%s\n", buff);	
		}
		else
		{
			break;
		}

	}
    printf("-disconnect\n");

    closesocket(my_sock);
    return 0;
}