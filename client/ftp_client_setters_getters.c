#include "ftp_client.h"

int control_fd = 0;
unsigned int data_port_no = 0;

void ftp_client_set_data_port_no(unsigned int port_num)
{
	data_port_no = port_num;

}

unsigned int ftp_client_get_data_port_no()
{
	if (0 == data_port_no) {
		printf("data port is not set\n");
		return 0;
	}

	return data_port_no;
}

void ftp_client_set_control_fd(int fd)
{
	control_fd = fd;
}

int ftp_client_get_control_fd()
{
	if (control_fd <= 0) {
		printf("control socket is not created\n");
		return -1;
	}

	return control_fd;
}
