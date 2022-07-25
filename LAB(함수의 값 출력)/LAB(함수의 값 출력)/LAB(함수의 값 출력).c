#include <stdio.h>

int h(int i)
{
	int n;
	int ret = 0;

	if (i == 0 || i == 1)
		return 1;
	
	for (n = 0; n < i; n++)
		ret = ret + h(n) * h(i - (n + 1));

	return ret;
}
int main(void)
{
	int n;
	printf("Input a number: ");
	scanf_s("%d", &n);

	printf("H(%d) : %d\n", n, h(n));
}