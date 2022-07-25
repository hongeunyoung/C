#include<stdio.h>
#include<malloc.h>

int main() {
	int test, distance;
	int* map;
	scanf_s("%d", &test);

	for (int i = 0; i < test; i++) {
		scanf_s("%d", &distance);
		map = (int*)malloc(sizeof(int) * distance);

		for (int j = 0; j < distance; j++)
			scanf_s("%d", &map[j]);

		for (int k = 0; k <= (sizeof(map) / sizeof(int)) + 1; k++)
			printf("%d ", map[k]);

		printf("\n");
	}
	return 0;
}