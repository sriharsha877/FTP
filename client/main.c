#include "ftp.h"

int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("Usage : %s <Ip address> <port>\n", argv[0]);
		return -1;
	}
	
	GMainLoop *loop;

	loop = g_main_loop_new(NULL, FALSE);

	ftp_client_set_main_loop_variable(loop);

	ftp_client_init(argv[1], argv[2]);
	
	g_main_loop_run(loop);
	return 0;
}
