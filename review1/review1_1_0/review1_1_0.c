#include <stdio.h> 
#include <string.h> 
void print_reverse(char *str, int end) {
	if (end == 0) {
		printf("%c", str[end]);
		return;
	}

	printf("%c", str[end]);
	print_reverse(str, --end);
} 

int main() { 
	char str[100]; 
	
	printf("Enter any string:"); 
	scanf_s("%s", str, sizeof(str));
	str[strlen(str)] = '\0';
	
	printf("Reversed String is: "); 
	print_reverse(str, strlen(str) - 1);
} 