#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN_API 46
char apiKey[MAXLEN_API];
char *deviceToSendIdentifer;




void push(char *types, char *title, char *body)
{ 
	char msg_title[400];
	char msg_body[400];

	sprintf(msg_title, "'%s'",title);
	sprintf(msg_body, "'%s'",body);


	printf("%s",title);
	char command[400];
    // write total string to command, including "> report.json" 
    // to have transmission report (JSON format) sent to txt file not stdin.
    sprintf(command, "curl https://api.pushbullet.com/api/pushes \
        -u %s: \
        -d device_iden=%s \
        -d type=%s \
        -d title=%s \
        -d body=%s \
        -X POST \
        > report.json", apiKey, deviceToSendIdentifer, types, msg_title, msg_body);

        system(command);
}

void setup()
{
	int count = 0;
	int deviceToSendNumber;


	//char apiKey[MAXLEN_API];
	char buffer[400];

	char devices[3][22+1];
	char names[3][10+1];

	char *string_device;
	char *string_name;
	char *string_device_short;
	char *string_name_short;

	printf("Enter your APIkey\n");
	fgets(apiKey, MAXLEN_API, stdin);

	snprintf(buffer, sizeof(buffer), "curl -u %s: https://api.pushbullet.com/api/devices > DeviceCall.txt",apiKey);
	system(buffer);

	FILE *devicefile;
	if((devicefile = fopen("DeviceCall.txt","r")) == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}

	FILE *namefile;
	if((namefile = fopen("DeviceCall.txt","r")) == NULL)
	{
		printf("Error opening file\n");
		exit(1);
	}

	//allocate memory and read in file
	//same file read twice but don't know how to fix
	//potential memory leak but not biggest concern

	if(!(string_device = malloc(500 * sizeof(char))))
	{
	printf("Could not allocate memory\n");
		exit(1);
	}

	fgets(string_device, 500, devicefile);

	if(!(string_name = malloc(500 *sizeof(char))))
	{
		printf("Could not allocate memory\n");
		exit(1);
	}
	fgets(string_name, 500, namefile);

	while(((strstr(string_device,"iden") != NULL)))
	{
		//find first iden and make it first place
		string_device_short = strstr(string_device,"iden");
		strncpy(devices[count], string_device_short +8, 22);
		string_device = string_device_short + 1;

		string_name_short = strstr(string_name,"model");
		strncpy(names[count], string_name_short + 9, 7);
		string_name = string_name_short + 1;

		printf("%d %s %s\n",count, names[count],devices[count]);

		count++;
	}

	printf("Please select device you want to send to\n");
	scanf("%d",&deviceToSendNumber);

	deviceToSendIdentifer = devices[deviceToSendNumber];
	printf("You selected\n");
	printf("%d %s %s\n",deviceToSendNumber, names[deviceToSendNumber], deviceToSendIdentifer);
	

	fclose(namefile);
	fclose(devicefile);
}