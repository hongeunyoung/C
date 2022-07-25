#include <stdio.h>

int main(void) {
	char num[53];
	int i, sum = 0;
	int temp1, temp2;
	int n2 = 0, n3 = 0, n4 = 0, n5 = 0;
	
	scanf_s("%s", num, sizeof(num));

	temp1 = num[strlen(num) - 1] - '0';

	if (temp1 % 2 == 0)
		n2 = 1;

	if (temp1 == 0 || temp1 == 5)
		n5 = 1;

	for (i = 0; i < strlen(num); i++)
		sum += (num[i] - '0');

	if (sum % 3 == 0)
		n3 = 1;

	temp2 = 10 * (num[strlen(num) - 2] - '0') + temp1;

	if (temp2 % 4 == 0)
		n4 = 1;

	printf("%d%d%d%d", n2, n3, n4, n5);
}