#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int box[500];
int count = 0;

int pick(int* items, int itemSize, int* bucket, int bucketSize, int k) {
	int i, lastIndex, smallest;
	int cnt = 0;
	int lastSelect;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			printf("%d ", items[bucket[i]]);

		printf("\n");

		return 1;
	}

	lastIndex = bucketSize - k - 1; //가장 최근에 뽑힌 수가 저장된 위치 i

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1; //조합
		//smallest = bucket[lastIndex]; //중복조합
		//smallest = 0; //중복순열

	lastSelect = -1; //절대 나오지 않을 값

	for (i = smallest; i < itemSize; i++) {
		if (lastSelect != items[i]) {
			lastSelect = items[i];
			bucket[lastIndex + 1] = i;
			cnt += pick(items, itemSize, bucket, bucketSize, k - 1);
		}
	}

	return cnt;
}

int main() {
	int bucket[9];
	int N, R;
	int i;
	int items[9];

	scanf_s("%d %d", &N, &R);

	for (i = 0; i < N; i++)
		scanf_s("%d", &items[i]);

	//pick(items, N, bucket, R, R);
	printf("%d\n", pick(items, N, bucket, R, R));
}