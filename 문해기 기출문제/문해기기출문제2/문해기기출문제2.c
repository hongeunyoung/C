#include <stdio.h>

int main(void) {
	int num, i, j, k, game = 0, count;

	scanf_s("%d", &num);

	for (i = 0; i < num; i++) {
		game += 3;

		if (game >= 10) {
			count = 0;
			k = 0;

			for (j = game; j > 0; j /= 10) {
				count++;

				if (i < num) {
					k++;
					i++;
				}
			}

			if (i == num) {
				for (j = k; j < count; j++)
					game /= 10;

				game %= 10;
			}
			else
				i--;
		}
	}

	printf("%d", game);
}