#ifndef CPU_H
#define CPU_H

void cpu_write_vendor(char *);
void cpu_write_hv_vendor(char *);
void cpu_write_brand(char *);
int cpu_rdtsc();

#endif
