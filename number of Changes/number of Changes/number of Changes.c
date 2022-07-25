#include <stdio.h>

int pick(int n, int k) {
	int item, lastIndex;
	int money[4] = { 10, 50, 100, 500 };
	int count = 0;

	if (k == 1) {
		if ((n % money[0]) == 0)
			return 1;
		else
			return 0;
	}

	lastIndex = n / money[k - 1];

	for (item = lastIndex; item >= 0; item--)
		count += pick(n - (money[k - 1] * item), k - 1);

	return count;
}

int main(void) {
	int n;

	scanf_s("%d", &n);

	printf("%d", pick(n, 4));
}


/* ±³¼ö´Ô ¼öÁ¤
#include <stdio.h>

int pick(int n, int* coin, int coin_size, int k) {
	int item, lastIndex;
	int count = 0;

	if (k == 1) {
		if ((n % coin[0]) == 0)
			return 1;
		else
			return 0;
	}

	lastIndex = n / coin[k - 1];

	for (item = lastIndex; item >= 0; item--)
		count += pick(n - (coin[k - 1] * item), coin, coin_size, k - 1);

	return count;
}

int main(void) {
	int n;
	int money[4] = { 10, 50, 100, 500 };

	scanf_s("%d", &n);

	printf("%d", pick(n, money, 4, 4));
}
*/