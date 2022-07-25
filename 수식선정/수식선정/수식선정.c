#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int pick(int* items, int itemSize, int* bucket, int bucketSize, int k, int target) {
	int i, lastIndex, smallest;
	int total = 0;
	int found = FALSE;

	if (k == 0) {
		for (i = 0; i < bucketSize; i++)
			total += bucket[i] * (i + 1);

		if (total == target) {
			for (i = 0; i < bucketSize; i++) {
				if (bucket[i] == 1)
					printf(" + %d", i + 1);
				else
					printf(" - %d", i + 1);
			}

			printf(" = %d\n", total);

			return TRUE;
		}

		return FALSE;
	}
	
	lastIndex = bucketSize - k - 1; //가장 최근에 뽑힌 수가 저장된 위치 i
	smallest = 0; //중복순열

	//최소길이인 가능한 식 모두 출력(if 붙이면 발견하면 바로 끝)
	for (i = smallest; i < itemSize && !found; i++) {
		bucket[lastIndex + 1] = items[i];
		found = pick(items, itemSize, bucket, bucketSize, k - 1, target);
		
		if (found == TRUE)
			return TRUE;
	}

	//최소길이인 단 하나의 식 출력
	/*
	for(i = smallest; i < itemSize && !found; i++) {
		bucket[lastIndex + 1] = items[i];
		found = pick(items, itemSize, bucekt, bucketSize, k - 1, target);
	}
	*/

	return found;
}

int main(void) {
	int items[] = { 1, -1 };
	int* bucket;
	int target;
	int i, sum = 0;
	int minBucketSize;
	int found = 0;

	scanf_s("%d", &target);

	bucket = (int*)malloc(sizeof(int) * target);

	for (i = 1; sum <= target; i++)
		sum += i;

	minBucketSize = i;

	for (i = minBucketSize; !found; i++) {
		found = pick(items, 2, bucket, i, i, target);
		//if (found)
			//printF("최소의 항 수는 %d\n", i);
	}
}