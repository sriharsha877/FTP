#include "ftp.h"
#include "ftp_client.h"

void ftp_client_init(char *server_ip, char *server_port)
{
	int ret = 0;
	int control_socket_fd = 0;
	struct sockaddr_in server_addr;

	printf("Entered into [%s]\n",  __func__);

	control_socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (control_socket_fd < 0) {
		printf("socket is failed : [%d]\n", control_socket_fd);
		return;
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = inet_addr(server_ip);
	server_addr.sin_port = htons(atoi(server_port));

	printf("connecting to server\n");
	
	ret = connect(control_socket_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
	if (ret < 0) {
		printf("connect failed : [%d]", ret);
		return;
	}

	printf("connect success\n");

	return;
}
