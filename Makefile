main: main.c cpu.c linux.c debuggers.c
	gcc -o elfish main.c cpu.c linux.c debuggers.c

clean: elfish
	rm elfish
