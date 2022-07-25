#include <stdio.h>

int main(void) {
	int a, b = 1, c;
	int i = 1;

	scanf_s("%d", &a);

	c = a * b;

	for (b = 1; c > 0; b++) {
		c = a * b;
		i = 1;

		if (c % 10 == 1) {
			while (1) {
				c /= 10;

				if (c % 10 != 1)
					break;

				i++;
			}
		}
	}

	printf("%d", i);
}