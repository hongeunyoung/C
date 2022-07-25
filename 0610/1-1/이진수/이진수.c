#include <stdio.h>

int main() {
	int T, n;

	scanf_s("%d", &T);

	for (int i = T; i > 0; i--) {
		scanf_s("%d", &n);

		//이진수가 작은 자리부터 하나씩 나오게 되기 때문에 1이면 그 위치(j)를 출력
		for (int j = 0; n > 0; j++) {
			if (n % 2 == 1)
				printf("%d ", j);
			n /= 2;
		}

		printf("\n");
	}

	return 0;
}