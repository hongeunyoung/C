#include <stdio.h>

int factorial(int n) {
    if (n < 2)
        return 1;

    return n * factorial(n - 1);
}

int main() {
    int N;
    scanf_s("%d", &N);
    printf("%d", factorial(N));
    return 0;
}