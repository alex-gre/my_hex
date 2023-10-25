#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "ws2_32")

int scan(char *ip, u_short port);

main(int argc, char *argv[])
{
	int start, end, i;
	char *ip;
	struct servent *srv;
	WSADATA wsd;
	char p_name[10] = " ";

	WSAStartup(0x0101, &wsd);

	ip = argv[1];
	start = atoi(argv[2]);
	end = atoi(argv[3]);

	for(i = start; i <= end; i++)
	{
		srv = getservbyport(htons(i), "tcp");
		(srv == NULL)?strcpy(p_name, "unknw"):strcpy(p_name, srv->s_name);
		if(scan(ip, i))
		{
			printf("%s(%d):\t Open\n", p_name, i);
		}
		else
		{
			printf("%s(%d):\t Close\n", p_name, i);
			continue;
		}
	}
}

int scan(char *ip, u_short port)
{
	SOCKET sd;
	WSADATA wsd;
	struct sockaddr_in loc;
	int res = 0;

	if(WSAStartup(0x0101, &wsd))
	{
		printf("wsd error\n");
		exit(1);
	}

	loc.sin_family	=	AF_INET;
	loc.sin_port	=	htons((u_short *)port);
	loc.sin_addr.s_addr = inet_addr(ip);

	sd = socket(AF_INET, SOCK_STREAM, 0);
	
	if(connect(sd, (struct sockaddr *)&loc, sizeof(loc)))
		res = 0;
	else
	{
		res = 1;
	}
closesocket(sd);
return res;
}