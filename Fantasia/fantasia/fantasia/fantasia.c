#include <stdio.h>

void fantasia(int n, int m, int ln, int lm, int rn, int rm) {
	if ((n == (ln + rn)) && (m == (lm + rm)))
		return;

	if ((n * (lm + rm)) < (m * (ln + rn))) {
		printf("L");
		return fantasia(n, m, ln, lm, (ln + rn), (lm + rm));
	}
	else {
		printf("R");
		return fantasia(n, m, (ln + rn), (lm + rm), rn, rm);
	}
}

int main(void) {
	int n, m;

	scanf_s("%d %d", &n, &m);

	fantasia(n, m, 0, 1, 1, 0);
}