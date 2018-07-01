#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <glib.h>
#include <sys/types.h>
#include <sys/stat.h>

#define LS "ls"
#define PWD "pwd"
#define RENAME_FILE "rename"
#define CHANGE_DIR "chd"
#define CREATE_DIR "mkdir"
#define BYE "bye"
#define EXIT "exit"
#define QUIT "quit"
#define HELP "help"

void ftp_client_list_all_files(char *command);
void ftp_client_present_working_directory();
void ftp_client_change_present_directory(char *dir_name);
void ftp_client_create_directory(char *dir_name);
void ftp_client_rename_file(char *src_file, char *dest_file);
void ftp_client_close_control_connection(int control_fd);
void ftp_client_close_data_connection(int data_fd);
