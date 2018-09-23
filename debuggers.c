#include<string.h>
#include<stdbool.h>
#include<fcntl.h>
#include<unistd.h>
#include<ctype.h>
#include "debuggers.h"

bool debug_isdebuggerpresent(){
	char buf[4096];
	char tracerpid[] = "TracerPid:";

	const int s_fd = open("/proc/self/status",O_RDONLY);
	if(s_fd == -1){
		return false;
	}

	const ssize_t r_num = read(s_fd,buf,sizeof(buf)-1);
	if(r_num <= 0){
		return false;
	}
	buf[r_num] = '\0';

	char *tracerpid_ptr = strstr(buf,tracerpid);
	if(tracerpid_ptr == NULL){
		return false;
	}

	for(const char *chptr = tracerpid_ptr + sizeof(tracerpid)-1; tracerpid <= buf + r_num; ++chptr){
		if(isspace(*chptr)){
			continue;
		}else{
			return isdigit(*chptr) != 0 && *chptr != '0';
		}
	}
	return false;
}
