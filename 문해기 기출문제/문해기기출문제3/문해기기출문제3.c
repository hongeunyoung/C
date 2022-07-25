#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pick(int* items, int* bucket, int m, int k, int N) {
	int i, lastIndex, count = 0, answer = 0, sum;

	if (k == 0) {
		sum = 0;
		for (i = 0; i < m; i++) {
			if (items[bucket[i]] == 1) {
				sum += (i + 1);
			}
			else if (items[bucket[i]] == -1) {
				sum -= (i + 1);
			}	
		}

		if (sum == N) {
			count++;

		}
		return count;
	}

	lastIndex = m - k - 1;

	for (i = 0; i < 2; i++) {
		bucket[lastIndex + 1] = i;
		answer += pick(items, bucket, m, k - 1, N);
	}

	return answer;
}

int main(void) {
	int items[] = { 1, -1 };
	int N;
	int* bucket;
	int i, sum = 0;

	scanf_s("%d", &N);
	bucket = (int*)malloc(sizeof(int) * N);

	for (i = N; i > 0; i--) {
		sum += pick(items, bucket, i, i, N);
	}

	printf("%d", sum);

	return;
}