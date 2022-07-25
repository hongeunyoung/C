#include <stdio.h>

int main() {
	int max = 0, total = 0;
	int off, on;

	for (int i = 0; i < 10; i++) {
		scanf_s("%d %d", &off, &on);
		total += (-off + on);

		if (total > max)
			max = total;
	}

	printf("%d", max);
	return 0;
}