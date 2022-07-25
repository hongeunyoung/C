#include <stdio.h>
#include <stdlib.h>

int pick(int n, int* student, int bucketSize, int k, int* bucket, int* bucket2, int memo, int index) {
	int i, j = 0, l = 0, lastIndex, smallest, item, sum1 = student[5], sum2 = 0, result;

	if (k == 0) {
		for (i = 0; i < n; i++) {
			if (i == bucket[l])
				sum1 += student[bucket[l]];
			else
				bucket2[j++] = i;
		}

		for (i = 0; i < bucketSize + 1; i++)
			sum2 += student[bucket2[i]];

		result = sum1 - sum2;

		if (result < 0)
			result = -result;

		if (memo < 0)
			memo = result;
		else if (memo > result)
			memo = result;

		return memo;
	}

	lastIndex = bucketSize - k - 1;

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1;

	for (item = smallest; item < n; item++) {
		bucket[lastIndex + 1] = item;
		pick(n, student, bucketSize, k - 1, bucket, bucket2, memo, index);
	}
}

int main(void) {
	int n, m = 1, i, num, memo = -1, index = 0;
	int* student, bucket, bucket2;

	scanf_s("%d", &n);
	student = (int*)malloc(sizeof(int) * n);
	bucket = (int*)malloc(sizeof(int) * n / 2);
	bucket2 = (int*)malloc(sizeof(int) * n / 2);

	for (i = 0; i < n; i++)
		scanf_s("%d", &student[i]);

	num = (n / 2) - 1;

	printf("%d", pick(n - 1, student, num, num, bucket, bucket2, memo, index));

	free(student);
	free(bucket);
	free(bucket2);
}