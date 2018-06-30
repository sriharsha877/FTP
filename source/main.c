#include "ftp.h"

int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("Usage : %s <Ip address> <port>\n", argv[0]);
		return -1;
	}
	GMainLoop *loop;

	loop = g_main_loop_new(NULL, FALSE);

	g_main_loop_run(loop);
	return 0;
}
