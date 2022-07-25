#include <stdio.h>

int main() {
    int M, N;
    int min = -1, sum = 0;
    scanf_s("%d%d", &M, &N);

    for (int i = M; i <= N; i++) {
        for (int j = 2; j <= i; j++) {
            if (i % j == 0 && j != i)
                break;

            if (j == i || i == 2) {
                if (min == -1)
                    min = i;

                sum += i;
            }
        }
    }

    if (min == -1)
        printf("-1");
    else
        printf("%d\n%d", sum, min);

    return 0;
}