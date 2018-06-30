#include "ftp.h"

#define MAX_CLIENT_CONNECTIONS 10

void ftp_server_init(char *control_socket_port)
{
	int ret = 0;
	int server_fd = 0;
	socklen_t length = 0;
	int used = 1;
	int new_fd = 0;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;

	printf("Entered into %s\n", __func__);
	
	server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (0 > server_fd) {
		printf("socket failed : %d\n", ret);
		return;
	}
	
	ret = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &used, sizeof(int));
	if (0 > ret) {
		printf("setsockopt failed : %d\n", ret);
		return;
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(atoi(control_socket_port));

	ret = bind(server_fd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr));
	if (0 > ret) {
		printf("bind failed : %d\n", ret);
		return;
	}

	ret = listen(server_fd, MAX_CLIENT_CONNECTIONS);
	if (0 > ret) {
		printf("Listen failed : %d\n", ret);
		return;
	}

	printf("Listening for connections\n");

	new_fd = accept(server_fd, (struct sockaddr *)&client_addr, &length);
	if (new_fd <= 0) {
		printf("AAccept failed: %d\n", new_fd);
		return;
	}

	printf("Connection success: %d\n", new_fd);

}
int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("Usage : %s <Ip address> <port>\n", argv[0]);
		return -1;
	}
	GMainLoop *loop;

	loop = g_main_loop_new(NULL, FALSE);
	
	ftp_server_init(argv[1]);

	g_main_loop_run(loop);
	return 0;
}
