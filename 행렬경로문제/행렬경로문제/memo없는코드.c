#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int** m;
	int i, j, r, c;
	r = c = 4; // 4x4 matrix
	m = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++)
		m[i] = (int*)malloc(sizeof(int) * c);
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			scanf_s("%d", &m[i][j]);
	printf("%d\n", matrixPath(m, r, c, 3, 3));
}

int matrixPath(int** m, int r, int c, int i, int j)
{
	if (i == 0 && j == 0) return m[i][j];
	else if (i == 0)
		return matrixPath(m, r, c, 0, j - 1) + m[i][j];
	else if (j == 0)
		return matrixPath(m, r, c, i - 1, j) + m[i][j];
	else
	{
		int a, b;
		a = matrixPath(m, r, c, i - 1, j);
		b = matrixPath(m, r, c, i, j - 1);
		return ((a < b) ? a : b) + m[i][j];
	}
}