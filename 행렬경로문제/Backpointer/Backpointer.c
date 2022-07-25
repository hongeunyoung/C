#include <stdio.h>
#include <stdlib.h>

void print_path(int i, int j, int** BP) {
	//trivial case

	//recursion
	if (BP[i][j] == UP)
		print_path(i - 1, j, BP);
	else if (BP[i][j] == LE)
		print_path(i, j - 1, BP);
	printf("<%d, %d> ", i, j);
}