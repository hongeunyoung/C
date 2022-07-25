#include <stdio.h>

int main() {
    int n;
    int a0 = 0, a1 = 1, a2;

    scanf_s("%d", &n);

    if (n == 0) {
        printf("0");
    }
    else {
        for (int i = 0; i < n; i++) {
            a2 = a0 + a1;
            a0 = a1;
            a1 = a2;
        }

        printf("%d", a0);
    }

    return 0;
}