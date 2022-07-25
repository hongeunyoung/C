#include <stdio.h>

void star(int i, int j, int n) {
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
        printf(" ");
    else {
        if (n == 1)
            printf("*");
        else
            star(i, j, n / 3);
    }
}

int main() {
    int N;
    scanf_s("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            star(i, j, N / 3);
        printf("\n");
    }

    return 0;
}