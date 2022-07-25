#include <stdio.h>

int rn = 0;
int count = 0;

int calculateReverse(int n) {
	int bp;

	if (n / 10 == 0) {
		bp = 10 * rn + n;
		rn = 0;

		return bp;
	}

	bp = n % 10;
	rn = 10 * rn + bp;

	return calculateReverse(n / 10);
}

/*
void palindrome(int n1) {
	int n2 = calculateReverse(n1);
	int sum = n1 + n2;

	if (n1 < 0 || sum < 0) {
		printf("Overflow");
		return;
	}

	if (n1 < 10) {
		printf("%d %d", count, n1);
		return;
	}

	count++;

	if (sum != calculateReverse(sum))
		return palindrome(sum);
	else {
		printf("%d %d", count, sum);
		return;
	}
}*/

int main(void) {
	int num1, num2;
	int sum, count = 0;

	scanf_s("%d", &num1);

	//palindrome(num);

	while (1) {
		num2 = calculateReverse(num1);

		if (num1 == num2) {
			printf("%d %d", count, num1);
			break;
		}

		sum = num1 + num2;

		if (sum < 0) {
			printf("Overflow");
			break;
		}

		count++;

		if (sum == calculateReverse(sum)) {
			printf("%d %d", count, sum);
			break;
		}

		num1 = sum;
	}
}