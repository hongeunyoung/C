# include <stdio.h>
# include <string.h>

int check(char s[]) {
	int i;
	int length = strlen(s);

	for (i = 0; i < length / 2; i++) {
		if (s[i] != s[length - i - 1])
			return 1;
	}

	return 0;
}

void palindrome(char s[], int count, int length, char a[]) {
	int index, i;
	int temp = length;

	if (check(a) == 0)
		return;

	index = length - count - 1;

	for (i = index; i >= 0; i--) {
		a[temp] = s[i];
		temp++;
	}

	a[temp] = '\0';

	if (check(a) == 0)
		return;
	else
		palindrome(s, count - 1, length, a);
}

int main(void) {
	char s[100];
	char answer[100];
	int length;

	scanf_s("%s", s, sizeof(s));
	length = strlen(s);
	strcpy_s(answer, sizeof(s), s);

	palindrome(s, length - 1, length, answer);

	printf("%s", answer);
}