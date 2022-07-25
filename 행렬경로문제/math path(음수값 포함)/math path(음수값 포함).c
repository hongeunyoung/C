#include <stdio.h>
#include <stdlib.h>

#define ST 1
#define LE 2
#define UP 3

int matrixPath(int** m, int r, int c, int i, int j, int** M, int** BP) {
	int ret;

	if (M2[i][j] != 0)
		return M[i][j];

	if (i == 0 && j == 0) {
		BP[i][j] = ST;

		return m[i][j];
	}
	else if (i == 0) {
		ret = matrixPath(m, r, c, i, j - 1, M, BP) + m[i][j];
		BP[i][j] = LE;
	}
	else if (j == 0) {
		ret = matrixPath(m, r, c, i - 1, j, M, BP) + m[i][j];
		BP[i][j] = UP;
	}
	else {
		int a, b;
		a = matrixPath(m, r, c, i - 1, j, M, BP);
		b = matrixPath(m, r, c, i, j - 1, M, BP);
		ret = ((a < b ? a : b)) + m[i][j];
		BP[i][j] = (a < b) ? UP : LE;
	}

	M[i][j] = ret;

	return M[i][j];
}

int print_path(int** BP, int i, int j) {
	if (BP[i][j] == ST) {
		printf("<%d, %d>", i, j);
	}
	else if (BP[i][j] == LE) {
		print_path(BP, i, j - 1);
		printf(" -> <%d, %d", i, j);
	}
	else if (BP[i][j] == UP) {
		print_path(BP, i - 1, j);
		printf(" -> <%d, %d", i, j);
	}
}
int main(void) {
	int** m;
	int** M;
	int** BP;
	int i, j, r, c;

	r = c = 4; //4x4 matrix

	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	BP = (int**)malloc(sizeof(int*) * r);

	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int*) * c);
		M[i] = (int*)malloc(sizeof(int*) * c);
		BP[i] = (int*)malloc(sizeof(int*) * c);
	}

	for (i = 0; i < r; i++) {
		for (j = 0; j < r; j++) {
			scanf_s("%d", &m[i][j]);
			M[i][j] = 0;
			BP[i][j] = 0;
		}
	}

	printf("%d\n", matrixPath(m, r, c, 3, 3, M, BP));

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%d ", BP[i][j]);
		}

		printf("\n");
	}

	print_path(BP, 3, 3);
}