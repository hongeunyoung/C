#include <stdio.h>

int main() {
	int A, B;
	int count = 1, total = 0;
	scanf("%d %d", &A, &B);

	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j < i; j++) {
			if (count > B) {
				printf("%d", total);
				return 0;
			}
				
			if (count >= A)
				total += i;

			count++;
		}
	}
}