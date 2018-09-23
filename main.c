#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<unistd.h>
#include<sys/utsname.h>
#include "cpu.h"
#include "types.h"
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

	printf("\t\tCPU brand: %s\n\n", cpu_brand);
	if (strlen(cpu_hv_vendor)){
		snprintf(aux, sizeof(aux) - sizeof(aux[0]), "CPU: %s (HV: %s) %s", cpu_vendor,cpu_hv_vendor, cpu_brand);
	}else{
		snprintf(aux, sizeof(aux) - sizeof(aux[0]), "CPU: %s %s", cpu_vendor,cpu_brand);
	}

	printf("[*] Debuggers detection\n");
	if(debug_isdebuggerpresent()){
		printf("...detect\n\n");
	}else{
		printf("...undetect\n\n");
	}

	printf("[*] CPU information based detections\n");
	printf("...Checking the difference between CPU timestamp counters (rdtsc)\n");
	if(cpu_rdtsc() == TRUE){
		printf("...CPU VM traced by checking the difference between CPU timestamp counters (rdtsc)\n");
	}

	return 0;
}
