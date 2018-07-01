#include "ftp_client_operation.h"
#include <unistd.h>

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

	cur_dir_name = get_current_dir_name();
	if (NULL == cur_dir_name) {
		printf("get_current_dir_name failed");
		return;
	}

	printf("%s\n", cur_dir_name);

	g_free(cur_dir_name);

}
