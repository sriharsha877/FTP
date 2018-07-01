#include "ftp_client.h"
#include "ftp_client_operation.h"

#define MAX_LENGTH 25
void print_options()
{
	printf("Entered into : %s\n", __func__);

	printf("1. ls - Lists the contents in present directory\n"
	       "2. pwd - Process working directory in client side\n"
	       "3. chd - change directory in client side\n"
	       "4. mkdir - create directory\n"
	       "5. rename -  rename a file in client side\n"
	       "6. quit or exit or bye - Exit from ftp\n"
	       "6. help - displays options enabled\n");
}
void ftp_client_select_options()
{
	int i = 0;
	char *tok = NULL;
	int tok_count = 0;
	char *option = NULL;
	char **choice = NULL;

	printf("Entered into %s\n", __func__);

	print_options();
	
	option = g_malloc0(MAX_LENGTH);
	if (!option) {
		printf("malloc failed\n");
		return;
	}

	while(1) {
		printf("myftp-->");
		if (NULL == fgets(option, 80, stdin)) {
			printf("fgets failed\n");
			continue;
		}

		option[strlen(option) - 1] = '\0';

		if (*option == '\0') {
			continue;
		}
		
		while (' ' == *option)
			memmove(option, option+1, strlen(option+1)+1);

		choice = g_strsplit(option, " ", -1);

		if ((NULL == choice) || (NULL == choice[0])) {
			printf("Invalid choice\n");
			continue;
		}

		for(i = 0; NULL != choice[i]; i++)
			tok_count++;

		printf("The token count is : %d\n", tok_count);

		if (!g_strcmp0(LS, choice[0])) {
			ftp_client_list_all_files(option);
		} else if (!g_strcmp0(PWD, choice[0]) && (tok_count == 1)) {
			ftp_client_present_working_directory();
		} else if (!g_strcmp0(RENAME_DIR, choice[0])) {
			printf("option for rename dir\n");
		} else if (!g_strcmp0(CHANGE_DIR, choice[0])) {
			printf("option for change dir\n");
		} else if (!g_strcmp0(CREATE_DIR, choice[0])) {
			printf("option for create directory\n");
		} else if (!g_strcmp0(BYE, choice[0]) || !(g_strcmp0(EXIT, choice[0])) || !(g_strcmp0(QUIT, choice[0]))) {
			printf("ftp is quiting\n");
			break;
		} else if (!g_strcmp0(HELP, choice[0])) {
			printf("Help!!!!!!!!!!\n");
			print_options();
			g_strfreev(choice);
			tok_count = 0;
			continue;
		} else {
			printf("Invalid choice!!!!!!!!!\n");
		}
		
		g_strfreev(choice);
		tok_count = 0;
	}
	
	g_free(option);
	return;
		
}
