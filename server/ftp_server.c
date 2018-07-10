#include "ftp.h"

#define MAX_CLIENT_CONNECTIONS 10
#define MAX_CLIENTS 100
#define MAX_BUF 512 

int client_fd[MAX_CLIENTS];

void ftp_server_accept_incoming_connections(int sock_fd)
{
	printf("[%s] fucntion entered\n", __func__);

	int i = 0;
	int ret = 0;
	int fd_max = 0;
	int new_fd = 0;
	fd_set read_fds;
	socklen_t length = 0;
	char *recv_msg = NULL;
	struct sockaddr_in client_addr;
	
	FD_ZERO(&read_fds);
	fd_max = sock_fd;

	while(1) {
		client_fd[sock_fd] = sock_fd;
		for(i = 0; i < fd_max; i++) {
			FD_SET(client_fd[i], &read_fds);
		}
		
		ret = select(fd_max + 1, &read_fds, NULL, NULL, NULL);
		if (ret < 0) {
			g_print("<%s:%s:%d> select failed\n", __FILE__, __func__, __LINE__);
			return;
		}


		if (FD_ISSET(sock_fd, &read_fds)) {
			new_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &length);
			if (new_fd < 0) {
				g_print("<%s:%s:%d> accept failed\n", __FILE__, __func__, __LINE__);
				return;
			}

			g_print("Connection accepted from : %s\n", inet_ntoa(client_addr.sin_addr));

			client_fd[new_fd] = new_fd;
			if (new_fd > fd_max)
				fd_max = new_fd;
		}

		for (i = 3; i < fd_max - 1; i++) {
			if (FD_ISSET(client_fd[i], &read_fds)) {
				recv_msg = g_malloc0(MAX_BUF);
				ret = recv(client_fd[i], recv_msg, MAX_BUF, 0);
				if (ret < 0) {
					g_print("<%s:%s:%d>recv failed\n", __FILE__, __func__, __LINE__);
					return;
				}

				g_print("Received message is : %s\n", recv_msg);
				g_free(recv_msg);
				recv_msg = NULL;
			}
		}

		FD_ZERO(&read_fds);

	}
}


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
	
	ret = setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT|SO_REUSEADDR, &used, sizeof(int));
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

	ftp_server_accept_incoming_connections(server_fd);


}
int main(int argc, char **argv)
{
	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		return -1;
	}
	GMainLoop *loop;

	loop = g_main_loop_new(NULL, FALSE);
	
	ftp_server_init(argv[1]);

	g_main_loop_run(loop);
	return 0;
}
