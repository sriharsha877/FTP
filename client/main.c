#include "ftp.h"

int main(int argc, char **argv)
{
	if (argc != 3) {
		printf("Usage : %s <Ip address> <port>\n", argv[0]);
		return -1;
	}
	
	//ftp_client_init(argv[1], argv[2]);
	
	ftp_client_select_options();

	return 0;
}
