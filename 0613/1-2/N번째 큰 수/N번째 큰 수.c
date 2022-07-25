#include <stdio.h>
#include <stdlib.h>

int sort() {
    int temp, n[10];

    for (int i = 0; i < 10; i++) {
        scanf_s("%d", &n[i]);

        for (int j = 0; j < i; j++) {
            if (n[j] > n[i]) {
                temp = n[i];
                n[i] = n[j];
                n[j] = temp;
            }
        }
    }

    return n[7];
}

int main() {
	int T;

	scanf_s("%d", &T);

	for (int i = 0; i < T; i++)
        printf("%d\n", sort());

    return 0;
}