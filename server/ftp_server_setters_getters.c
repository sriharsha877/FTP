#include "ftp_server.h"

GMainLoop *main_loop;

void ftp_client_set_main_loop_variable(GMainLoop *loop)
{
	if (NULL == loop) {
		printf("Loop variable is NULL");
		return;
	}

	main_loop = loop;

	return;
}

GMainLoop *ftp_client_get_main_loop_variable()
{
	if (NULL == main_loop) {
		printf("Loop variable is NULL");
		return NULL;
	}

	return main_loop;
}
