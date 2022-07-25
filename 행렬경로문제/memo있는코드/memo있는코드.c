#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int** m, ** M; // M은 메모
	int i, j, r, c;
	r = c = 4; // 4x4 matrix
	m = (int**)malloc(sizeof(int*) * r);
	M = (int**)malloc(sizeof(int*) * r);
	for (i = 0; i < r; i++) {
		m[i] = (int*)malloc(sizeof(int) * c);
		M[i] = (int*)malloc(sizeof(int) * c);
	}
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			scanf_s("%d", &m[i][j]);
			M[i][j] = 0; //메모 초기화
		}
	printf("%d\n", matrixPath_memo(m, r, c, 3, 3, M));
}


int matrixPath_memo(int** m, int r, int c, int i, int j, int** M)
{
	int ret;
	if (M[i][j] != 0)
		return M[i][j];

	if (i == 0 && j == 0)
		return m[i][j];
	else if (i == 0)
		ret = matrixPath_memo(m, r, c, i, j - 1, M) + m[i][j];
	else if (j == 0) 
		ret = matrixPath_memo(m, r, c, i - 1, j, M) + m[i][j];
	else {
		int a, b;
		a = matrixPath_memo(m, r, c, i - 1, j, M);
		b = matrixPath_memo(m, r, c, i, j - 1, M);
		ret = ((a < b) ? a : b) + m[i][j];
	}

	M[i][j] = ret;
	
	return M[i][j];
}