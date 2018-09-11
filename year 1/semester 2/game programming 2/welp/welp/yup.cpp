#include <stdio.h>

int main(int argc, char *argv[]) {
	const int j = 100;
	int* pointer[j];
	int array[j];
	for (int i = 0; i < j; i++) {
		array[i] = i;
		pointer[i] = &array[i];
		printf("%d\n", pointer[i]);
	}
	getchar();
}