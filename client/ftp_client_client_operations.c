#include "ftp_client_operation.h"
#include <unistd.h>

#define MAX_LENGTH 255

void ftp_client_list_all_files(char *command)
{
	if (NULL == command) {
		printf("command is NULL");
		return;
	}

	int ret = 0;

	ret = system(command);
	if (ret < 0) {
		printf("system failed");
		return;
	}

	return;
	
}

void ftp_client_present_working_directory()
{
	printf("Entered into %s\n", __func__);

	int ret = 0;
	char *cur_dir_name = NULL;

	cur_dir_name = g_malloc0(MAX_LENGTH);
	if (NULL == cur_dir_name) {
		printf("g_malloc0 is failed");
		g_free(cur_dir_name);
		return;
	}

	cur_dir_name = getcwd(cur_dir_name, MAX_LENGTH);
	if (NULL == cur_dir_name) {
		printf("get_current_dir_name failed");
		g_free(cur_dir_name);
		return;
	}

	printf("%s\n", cur_dir_name);

	g_free(cur_dir_name);
	cur_dir_name = NULL;

}

void ftp_client_rename_file(char *src_file, char *dest_file)
{
	printf("Entered into %s\n", __func__);

	int ret = 0;

	ret = rename(src_file, dest_file);
	if (0 > ret) {
		printf("rename failed : %d\n", ret);
		return;
	}

	printf("Success in renaming\n");
}

void ftp_client_change_present_directory(char *dir_name)
{
	printf("Entered into %s\n", __func__);

	int ret = 0;
	ret = chdir(dir_name);
	if (0 > ret) {
		printf("failed to change to %s  Error: %s", dir_name, ret);
		return;
	}

	printf("success in changing directory\n");
}

void ftp_client_create_directory(char *dir_name)
{
	printf("Entered into %s\n", __func__);

	int ret = 0;
	ret = mkdir(dir_name, S_IRWXU | S_IRWXG | S_IRWXO);
	if (0 > ret) {
		printf("mkdir failed : %d\n", ret);
		return;
	}

	printf("creating directory success\n");
}
