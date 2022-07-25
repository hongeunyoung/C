#include <stdio.h> 
#include <string.h> 

void reverse_string(char* str, int s, int e) {
	char bump;

	while(s < e) {
		bump = str[s];
		str[s] = str[e];
		str[e] = bump;

		s++;
		e--;
	}
}

int main() {
	char str[100];

	printf("Enter any string:");
	scanf_s("%s", str, sizeof(str));
	str[strlen(str)] = '\0';

	reverse_string(str, 0, strlen(str) - 1);
	printf("\nReversed String is: %s", str);
	return 0;
}