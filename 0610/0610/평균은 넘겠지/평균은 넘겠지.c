#include <stdio.h>
#include <stdlib.h>

int main() {
	int C, N, count, total;
	float rate, average;
	int *score;

	scanf_s("%d", &C);

	for (int i = C; i > 0; i--) {
		total = 0;
		count = 0;

		scanf_s("%d", &N);
		score = (int*)malloc(sizeof(int) * N);

		for (int j = 0; j < N; j++) {
			scanf_s("%d", &score[j]);
			total += score[j];
		}

		average = (float)total / N;
		for (int j = 0; j < N; j++)
			if (score[j] > average)
				count++;

		rate = (float)count / N * 100;
		printf("%.3f%%\n", rate);
	}
}