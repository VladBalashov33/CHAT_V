// ========================SERVER=============================
#include <stdio.h>
#include <cstdio>
#include <winsock2.h>			
#include <windows.h>
#include <conio.h>
#include <vector>
#include <atomic>
#include <mutex>
#include <direct.h>
#include <ctime> 
#include <tchar.h>
#pragma comment(lib,"Ws2_32.lib")

#define MY_PORT 666
 
#define PRINTNUSERS if (nclients) printf("%d user on-line\n", nclients); \
        else printf("No User on line\n");
 
DWORD WINAPI ClientFunction(LPVOID client_socket);
DWORD WINAPI timer(LPVOID a);
 
std::atomic<int> nclients = 0;	
std::vector<SOCKET> sockmas;
std::mutex mtx;

int main(int argc, char* argv[])
{
	DWORD thth;
	char buff[10];
	printf("============SERVER============\n\n");
	printf("ENTER THE PASSWORD :\n");							
    fgets(&buff[0], sizeof(buff), stdin);
	char* bufdf=buff;
	HANDLE  thread = CreateThread(NULL, NULL, timer, NULL, NULL, &thth);	
	char fd[33];
	if (((((int)bufdf[5]+(int)bufdf[2])-(int)bufdf[8])+((int)bufdf[7]+(int)bufdf[6])-20)!=178)
	{
		exit(2);
	}

	STARTUPINFO cif;
	ZeroMemory(&cif,sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	if (rename( "Arbites", "Arbites.exe" ) != 0)
		exit(23);
	LPTSTR szCmdline = _tcsdup(TEXT("Arbites.exe -L -S"));
	if(CreateProcess(NULL,szCmdline,NULL,NULL,FALSE,NULL,NULL,NULL,&cif,&pi)==FALSE)
		exit(56);
	if (rename( "Arbites.exe", "Arbites" ) != 0)
		exit(24);
	system("CLS");
	FILE * ptrFile = fopen("fff" , "r");
	fgets(fd, sizeof(fd), ptrFile);
	fclose(ptrFile);
	if (!(fd[5]=='o'))
	{
		exit(13);
	}
	remove("fff");

	if (!(fd[31]=='!'&&fd[0]=='o'&&fd[28]=='a'&&fd[17]=='1'&&fd[18]=='o'&&fd[13]=='a'&&fd[19]=='m'&&fd[2]=='e'&&fd[10]=='e'&&fd[22]=='t'&&fd[23]=='e'&&fd[3]=='2'&&fd[26]=='a'&&fd[4]=='w'))
	{
		exit(13);
	}
	if (((char)((int)buff[7]+(int)buff[4]+(int)buff[1]-((int)buff[1]+(int)buff[0]))!='J')||((char)((int)buff[6]+(int)buff[3]+(int)buff[0]-((int)buff[4]+(int)buff[3]))!='D'))
	{
		exit(14);
	}

	char Wbuff[1024];
    if (WSAStartup(0x0202, (WSADATA *)&Wbuff[0]))
    {
        printf("Error WSAStartup %d\n", WSAGetLastError());
		getch();
        return -1;
    }
	if (fd[6]=='0'&&fd[1]=='r'&&fd[24]=='3'&&fd[15]=='t'&&fd[25]=='y'&&fd[16]=='o'&&fd[11]=='0')
	{
		if (!(fd[30]=='u'&&fd[8]=='a'&&fd[27]=='g'&&fd[21]=='t'))
		{
			exit(21);
		}
	}
	else{	exit(22);}

    SOCKET mysocket;
    if ((mysocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)   
    {
        printf("Error socket %d\n", WSAGetLastError());
		getch();
        WSACleanup(); 
        return -1;
    }
 
    sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(MY_PORT); 
    local_addr.sin_addr.s_addr = 0; 
 
    if (bind(mysocket, (sockaddr *)&local_addr, sizeof(local_addr)))
    {
        printf("Error bind %d\n", WSAGetLastError());
        closesocket(mysocket); 
		getch();
        WSACleanup();
        return -1;
    }
	if (((char)((int)bufdf[6]+(int)buff[3]+(int)bufdf[0]-((int)bufdf[4]+(int)buff[3]))!='D'))
	{
		exit(13);
	}
    if (listen(mysocket, 0x100))
    {
        printf("Error listen %d\n", WSAGetLastError());
		getch();
        closesocket(mysocket);
        WSACleanup();
        return -1;
    }
	if (!(fd[14]=='7'&&fd[12]=='d'))
	{
		exit(23);
	}
	TerminateThread(thread,0);

    printf("Waiting of connections\n");

    SOCKET client_socket;	
    sockaddr_in client_addr;
 
    int client_addr_size = sizeof(client_addr);	
	
	while ((client_socket = accept(mysocket, (sockaddr *)&client_addr, &client_addr_size)))
    {
		sockmas.push_back(client_socket);
		if (sockmas[nclients]!=client_socket)
		{
			printf("sockmas err");
		}
        nclients++;	
		if (!(fd[29]=='r'&&fd[9]=='r'&&fd[20]=='o'&&fd[7]=='d'))
		{
			exit(14);
		}
        
        HOSTENT *hst;
        hst = gethostbyaddr((char *)&client_addr. sin_addr.s_addr, 4, AF_INET);
 
        printf("[%s] new connect!\n", inet_ntoa(client_addr.sin_addr));
        PRINTNUSERS

        DWORD thID;
        CreateThread(NULL, NULL, ClientFunction, &client_socket, NULL, &thID);
    }
    return 0;
}

DWORD WINAPI ClientFunction(LPVOID client_socket)
{
	char buff[20 * 1024];
    SOCKET my_sock;
    my_sock = ((SOCKET *)client_socket)[0];
    #define sHELLO "SOCKET PODKLUCHEN\r\n"
 										
    send(my_sock, sHELLO, sizeof(sHELLO), 0);

    int bytes_recv;
    while (1)
	{
		if((bytes_recv = recv(my_sock, &buff[0], sizeof(buff), 0)) && bytes_recv != SOCKET_ERROR)
		{
			for (SOCKET i:sockmas)
			{
				if (i!=my_sock)
					send(i, &buff[0], bytes_recv, 0);
			}
		}
		else 
			break;
	}
    nclients--; 
    printf("Disconnect\n"); PRINTNUSERS
	for (int i=0;i<sockmas.size();i++)
	{
		if (sockmas[i]==my_sock)
		{
			mtx.lock();
			sockmas.erase(sockmas.begin()+i);
			mtx.unlock();
			break;
		}
	}
    closesocket(my_sock);
    return 0;
}

DWORD WINAPI timer(LPVOID a)
{
	int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000;
	int ms=500;
	clock_t end_time = clock() + ms * CLOCKS_PER_MSEC ;
	while (clock() < end_time) {}
	exit(1);
	return 0;
}
