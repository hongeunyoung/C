#include <stdio.h>
#include <stdlib.h>

int flag = 0;

pick(int n, int* bucket, int k, int N) {
	int i, lastIndex, sum = 0;
	int* num;

	if (k == 0) {
		for (i = 0; i < n; i++) {
			num = (int*)malloc(sizeof(int) * n);

			if (bucket[i] == 0) {
				num[i] = (i + 1);
				sum += (i + 1);
			}
			else {
				num[i] = -(i + 1);
				sum -= (i + 1);
			}

			free(num);
		}

		if (sum == N) {
			flag = 1;
			return;
		}
		sum = 0;

		return;
	}

	lastIndex = n - k - 1;

	for (i = 0; i < 2; i++) {
		bucket[lastIndex + 1] = i;
		pick(n, bucket, k - 1, N);
	}
}

int main(void) {
	int n, N;
	int* bucket;

	scanf_s("%d %d", &n, &N);
	bucket = (int*)malloc(sizeof(int) * n);

	pick(n, bucket, n, N);

	printf("%d", flag);

	free(bucket);
}