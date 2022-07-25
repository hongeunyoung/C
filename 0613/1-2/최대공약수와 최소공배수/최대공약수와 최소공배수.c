#include <stdio.h>

void solution(int n1, int n2, int a, int gcd) {
	for (int i = a; i <= (n1 < n2 ? n1 : n2); i++) {
		if (n1 % i == 0 && n2 % i == 0) {
			solution(n1 / i, n2 / i, i, gcd * i);
			return;
		}
	}

	printf("%d\n%d", gcd, gcd * n1 * n2);
}

int main() {
	int n1, n2;
	scanf_s("%d %d", &n1, &n2);

	solution(n1, n2, 2, 1);
	return 0;
}