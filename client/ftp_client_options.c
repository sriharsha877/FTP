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

void remove_extra_spaces(char *option)
{
	int i = 0;

	// Fopr removing starting zeros	
	while (' ' == *option)
		memmove(option, option+1, strlen(option+1)+1);

	// removing ending zeros
	while(' ' == option[strlen(option) - 1])
		option[strlen(option) - 1] = '\0';

	for (i = 1; option[i]; i++) {
		// moving middle extra spaces
		if ((option[i] == ' ') && (option[i] == option[i+1])) { 
			memmove(option+i, option+i+1, strlen(option+i+1)+1);
			i--;
		}
	}

}

void ftp_client_select_options()
{
	int i = 0;
	char *tok = NULL;
	char **choice = NULL;
	int tok_count = 0;
	char *option = NULL;

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
		
		remove_extra_spaces(option);
		
		choice = g_strsplit(option, " ", -1);
		while(choice[i++] != NULL) 
			tok_count++;
		
		if (!g_strcmp0(LS, choice[0])) {
			ftp_client_list_all_files(option);
		} else if (!g_strcmp0(PWD, choice[0])) {
			if (tok_count != 1) {
				printf("Usage : pwd\n");
			} else {
				ftp_client_present_working_directory();
			}
		} else if (!g_strcmp0(RENAME_FILE, choice[0])) {
			if (tok_count != 3) {
				printf("Usage : rename <src_file> <dest_file>\n");
			} else {
				ftp_client_rename_file(choice[1], choice[2]);
			}	
		} else if (!g_strcmp0(CHANGE_DIR, choice[0])) {
			if (2 != tok_count) {
				printf("Usage : chd <dir_name>");
			} else {
				ftp_client_change_present_directory(choice[1]);
			}
		} else if (!g_strcmp0(CREATE_DIR, choice[0])) {
			if (2 != tok_count) {
				printf("Usage : mkdir <dir_name>");
			} else {
				ftp_client_create_directory(choice[1]);
			}
		} else if (!g_strcmp0(BYE, choice[0]) || !(g_strcmp0(EXIT, choice[0])) || !(g_strcmp0(QUIT, choice[0]))) {
			printf("ftp is exiting\n");
			break;
		} else if (!g_strcmp0(HELP, choice[0])) {
			print_options();
			i = 0;
			tok_count = 0;
			g_strfreev(choice);
			continue;
		} else {
			printf("Invalid choice!!!!!!!!!\n");
		}
		i = 0;	
		tok_count = 0;
		g_strfreev(choice);
	}
	g_free(option);
	return;
		
}
