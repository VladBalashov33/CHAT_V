#include <stdio.h>		
#include <windows.h>
#include <conio.h>
#include "md5.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <ctime> 
using namespace std;
DWORD WINAPI timer(LPVOID a);
void main()
{
	DWORD thth;
	HANDLE  thread = CreateThread(NULL, NULL, timer, NULL, NULL, &thth);
	MD5 md5 ;
	char ddd[33]={98,51,56,-110,56,108,98,53,48,99,51,101,56,50,99,96,100,-105,97,101,54,-112,54,-103,48,55,97,-107,54,-105,99,100};
	for (int i=0;i<=28;i+=3)
	{
		if (i%2==0)
		{
			char z=ddd[i+1];
			ddd[i+1]=ddd[i];
			ddd[i]=z;
		}
		else
		{
			char z=ddd[i-1];
			ddd[i-1]=ddd[i];
			ddd[i]=z;
		}
	}
	for (int i=2;i<=31;i+=3)
	{
		if (i%2==0)
		{
			ddd[i]=(char)((int)ddd[i]-(int)ddd[i-2]+7);
		}
		else
		{
			ddd[i]=(char)((int)ddd[i]-(int)ddd[i+1]+1);
		}
	}

	char* fff=md5.digestFile("SERVER_V.exe");
	if(!(fff[0]==ddd[3]&&fff[1]==ddd[1]&&fff[2]==ddd[5]&&fff[3]==ddd[0]&&fff[4]==ddd[7]&&fff[5]==ddd[2]&&fff[6]==ddd[9]&&fff[7]==ddd[4]&&fff[8]==ddd[11]&&fff[9]==ddd[6]&&fff[10]==ddd[13]))
	{
		exit(1);
	}

	if(!(fff[5]==ddd[2]&&fff[6]==ddd[9]&&fff[7]==ddd[4]&&fff[8]==ddd[11]&&fff[9]==ddd[6]&&fff[10]==ddd[13]&&fff[11]==ddd[8]&&fff[12]==ddd[15]&&fff[13]==ddd[10]&&fff[14]==ddd[17]&&fff[15]==ddd[12]&&fff[16]==ddd[19]&&fff[17]==ddd[14]&&fff[18]==ddd[21]&&fff[19]==ddd[16]&&fff[20]==ddd[23]&&fff[21]==ddd[18]&&fff[22]==ddd[25]&&fff[23]==ddd[20]&&fff[24]==ddd[27]&&fff[25]==ddd[22]&&fff[26]==ddd[29]))
	{
		exit(2);
	}
	ofstream ofs("fff"); 
	ofs <<"ore2wo0dare0da7to1omotte3yagaru!";
	ofs.close();
	if(!(fff[0]==ddd[3]&&fff[1]==ddd[1]&&fff[2]==ddd[5]&&fff[3]==ddd[0]&&fff[4]==ddd[7]&&fff[26]==ddd[29]&&fff[27]==ddd[24]&&fff[28]==ddd[31]&&fff[29]==ddd[26]&&fff[30]==ddd[30]&&fff[31]==ddd[28]))
	{
		exit(3);
	}
	exit(10);
}
DWORD WINAPI timer(LPVOID a)
{
	int CLOCKS_PER_MSEC = CLOCKS_PER_SEC / 1000;
	int ms=500;
	clock_t end_time = clock() + ms * CLOCKS_PER_MSEC ;
	while (clock() < end_time) {}
	exit(4);
	return 0;
}