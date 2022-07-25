#include <stdio.h>

int main() {
	int N, num;
	int min, max;

	scanf_s("%d", &N);

	for (int i = N; i > 0; i--) {
		scanf_s("%d", &num);

		if (i == N) {
			min = num;
			max = num;
		}
		else {
			if (num < min)
				min = num;
			
			if (num > max)
				max = num;
		}
	}

	printf("%d %d", min, max);
	return 0;
}