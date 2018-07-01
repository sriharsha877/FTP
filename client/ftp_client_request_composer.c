#include "ftp_client_composer.h"
#include "ftp_client.h"

const char *ftp_client_compose_request(char *command, char *data)
{
	const char *req_string = NULL;
	unsigned int data_port_no = 0;

	json_object *req_object = json_object_new_object();

	json_object *cmd_string = json_object_new_string(command);
	json_object *data_string = json_object_new_string(data);
	
	data_port_no = ftp_client_get_data_port_no();
	json_object *data_port = json_object_new_int(data_port_no);

	json_object_object_add(req_object, "command", cmd_string);
	json_object_object_add(req_object, "data", data_string);
	json_object_object_add(req_object, "data_port", data_port);

	req_string = json_object_to_json_string(req_object);
	
	printf("Json string is : %s\n", req_string);
	return req_string;
	
}
