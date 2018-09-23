#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<unistd.h>
#include<sys/utsname.h>
#include "cpu.h"
#include "linux.h"
#include "debuggers.h"

int main(void){
	char cpu_vendor[13];
	char cpu_hv_vendor[13];
	char cpu_brand[49];

	char aux[1024];
	struct utsname s;

	cpu_write_vendor(cpu_vendor);
	cpu_write_hv_vendor(cpu_hv_vendor);
	cpu_write_brand(cpu_brand);
	os_system_info(&s);

	printf("[*] start elfish\n");
	printf("[*] OS:\t\t%s %s\n",s.sysname,s.release);
	printf("[*] CPU:\t%s\n",cpu_vendor);

	if(strlen((cpu_hv_vendor))){
			printf("\t\tHypervisor: %s\n", cpu_hv_vendor);
	}

	printf("\t\tCPU brand: %s\n", cpu_brand);
	
	if (strlen(cpu_hv_vendor)){
		snprintf(aux, sizeof(aux) - sizeof(aux[0]), "CPU: %s (HV: %s) %s", cpu_vendor,cpu_hv_vendor, cpu_brand);
	}else{
		snprintf(aux, sizeof(aux) - sizeof(aux[0]), "CPU: %s %s", cpu_vendor,cpu_brand);
	}

	if(debug_isdebuggerpresent()){
		printf("[*] Debugger:\tdetect\n");
	}else{
		printf("[*] Debugger:\tundetect\n");
	}

	return 0;
}
