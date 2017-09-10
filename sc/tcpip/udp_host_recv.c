/* UDP datagram with boundary */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define BUF_SIZE 30

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int server_socket;
	struct sockaddr_in server_addr, client_addr;
	socklen_t client_addr_size;

	char message[BUF_SIZE];
	int str_len;
	int i;

	if (2 != argc) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	server_socket = socket(PF_INET, SOCK_DGRAM, 0);
	if (-1 == server_socket)
		error_handling("UDP socket creation error.");

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(argv[1]));

	if (-1 == bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)))
		error_handling("bind() error!");

	i = 0;
	while (1) {
		i++;
//              sleep(5);
//              printf("Read to receive message %d\n", i);

		/* recv and print datagram */
		client_addr_size = sizeof(client_addr);
		str_len = recvfrom(server_socket, message, BUF_SIZE, 0, (struct sockaddr *)&client_addr, &client_addr_size);
		/* the string will not append terminator automatically */
		message[str_len] = 0;
		printf("Message %3d : %s\n", i, message);

		sleep(5);
	}

	close(server_socket);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}