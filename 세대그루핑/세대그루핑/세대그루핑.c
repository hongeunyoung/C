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

	lastIndex = bucketSize - k - 1; //���� �ֱٿ� ���� ���� ����� ��ġ i

	if (bucketSize == k)
		smallest = 0;
	else
		smallest = bucket[lastIndex] + 1; //����
		//smallest = bucket[lastIndex]; //�ߺ�����
		//smallest = 0; //�ߺ�����

	lastSelect = -1; //���� ������ ���� ��

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