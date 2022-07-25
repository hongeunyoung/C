#include <stdio.h>
#include <stdlib.h>

long long H(int n, long long* memo) {
	int i;

	if (n == 1) {
		return 1;
	}

	if (memo[n] != 0)
		return memo[n];

	for(i = n - 1; i > 0; i--)
		memo[n] += ((n - i) * H(i, memo));

	return memo[n];
}

int main(void) {
	int n, i;
	long long* memo;

	scanf_s("%d", &n);
	memo = (long long*)malloc(sizeof(long long) * n);

	for (i = 0; i <= n; i++)
		memo[i] = 0;

	printf("%lld", H(n, memo));

	free(memo);
}