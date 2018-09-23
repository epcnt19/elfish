#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/utsname.h>
#include "linux.h"

void os_system_info(struct utsname *s){
	uname(s);
}
