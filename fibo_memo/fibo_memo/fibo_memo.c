#include <stdio.h>
#include <stdlib.h>

unsigned long long fib_memo(int n, int* M) {
	if (M[n] != 0)
		return M[n];

	if (n == 1 || n == 2)
		return 1;
	else {
		M[n] = fib_memo(n - 1, M) + fib_memo(n - 2, M);
		return M[n];
	}
}

int main() {
	int n, i;
	int* M;

	scanf_s("%d", &n);

	M = (int*)malloc(sizeof(int) * (n + 1));

	for (i = 0; i < n + 1; i++)
		M[i] = 0;

	printf("%llu\n", fib_memo(n, M));

	return 0;
}