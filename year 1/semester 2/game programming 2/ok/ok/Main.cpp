#include <stdio.h>
float x;
float* pointer;
int main(int argc, char *argv[]) {
	pointer = &x;
	printf("%x\n", pointer);
	getchar();
}