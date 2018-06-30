#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <glib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>


void ftp_client_init(char *server_ip, char *server_port);
void ftp_client_set_main_loop_variable(GMainLoop *loop);
GMainLoop *ftp_client_get_main_loop_variable();


void ftp_server_init(char *control_socket_port);
void ftp_client_set_main_loop_variable(GMainLoop *loop);
GMainLoop *ftp_client_get_main_loop_variable();
