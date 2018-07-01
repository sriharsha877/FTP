#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

void ftp_client_set_data_port_no(unsigned int port_no);
unsigned int ftp_client_get_data_port_no();
void ftp_client_set_control_fd(int fd);
int ftp_client_get_control_fd();
