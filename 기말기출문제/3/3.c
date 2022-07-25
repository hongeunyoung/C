#include <stdio.h>
#include <stdlib.h>

int X(int n, int* memo) {
	int m[3], i, num, min;

	for (i = 0; i < 3; i++)
		m[i] = 0;

	if (n == 2 || n == 3)
		return 1;

	if (memo[n] != 0)
		return memo[n];

	for (i = 0; i < 3; i++) {
		num = n;

		//m1
		if (n % 3 == 0 && i == 0) {
			m[0]++;
			m[0] += X(num / 3, memo);
		}

		//m2
		if (n % 2 == 0 && i == 1) {
			m[1]++;
			m[1] += X(num / 2, memo);
		}

		//m3
		if (i == 2) {
			m[2]++;
			m[2] += X(num - 1, memo);
		}
	}

	for (i = 0; i < 3; i++) {
		if (m[i] != 0) {
			min = m[i];
			break;
		}
	}

	while (i < 3) {
		if (m[i] != 0 && min > m[i])
			min = m[i];

		i++;
	}

	memo[n] = min;

	return memo[n];
}

int main(void) {
	int n, i;
	int* memo;

	scanf_s("%d", &n);
	memo = (int*)malloc(sizeof(int) * n);

	for (i = 0; i <= n; i++)
		memo[i] = 0;

	printf("%d", X(n, memo));

	free(memo);
}