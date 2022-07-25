#include <stdio.h>
int count = 0;
int c = 0;

int carry(int n1, int n2) {
	int num1, num2;

	num1 = n1 % 10;
	num2 = n2 % 10;

	if (n1 / 10 == 0 || n2 / 10 == 0) {
		if (num1 + num2 + c >= 10) {
			count++;
			c = 1;
			
			return carry(n1 / 10, n2 / 10);
		}

		return count;
	}

	if (num1 + num2 + c >= 10)
		count++;
	else
		c = 0;

	return(carry(n1 / 10, n2 / 10));
}

int main(void) {
	int num1, num2;

	scanf_s("%d %d", &num1, &num2);

	printf("%d", carry(num1, num2));
}