#include "ftp.h"
#include "ftp_client.h"

int main(int argc, char **argv)
{
	if (argc != 4) {
		printf("Usage : %s <Ip address> <server port> <data port>\n", argv[0]);
		return -1;
	}

	ftp_client_set_data_port_no(atoi(argv[3]));


	ftp_client_init(argv[1], argv[2]);
	
	ftp_client_select_options();

	return 0;
}
