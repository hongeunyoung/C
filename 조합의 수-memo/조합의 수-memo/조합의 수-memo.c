#include <stdio.h>
#include <stdlib.h>

int comb(int n, int r, int** M) {
	if (M[n][r] != 0)
		return M[n][r];

	if (r == 0 || r == n)
		return 1;
	else {
		M[n][r] = comb(n - 1, r - 1, M) + comb(n - 1, r, M);
		return M[n][r];
	}
}

int main() {
	int C, n, r, i, j;
	int** M;

	scanf_s("%d %d", &n, &r);

	M = (int*)malloc(sizeof(int*) * (n + 1));

	for (i = 0; i < n + 1; i++) {
		j = 0;
		M[i] = (int*)malloc(sizeof(int*) * (r + 1));

		for (j = 0; j < r + 1; j++)
			M[i][j] = 0;
	}

	C = comb(n, r, M);

	printf("RET = %d\n", C);

	return 0;
}