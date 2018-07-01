#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <glib.h>

void ftp_client_list_all_files(char *command);
void ftp_client_present_working_directory();
void ftp_client_chage_working_directory(char *dir_name);
void ftp_client_create_directory(char *dir_name);
void ftp_client_rename_file(char *src_file, char *dest_file);
void ftp_client_close_control_connection(int control_fd);
void ftp_client_close_data_connection(int data_fd);
