#include <stdio.h>

int main() {
    int N, num, count;
    scanf_s("%d", &N);

    count = N;

    for (int i = 0; i < N; i++) {
        scanf_s("%d", &num);

        if (num == 1)
            count--;

        for (int j = 2; j < num; j++) {
            if (num % j == 0) {
                count--;
                break;
            }
        }
    }

    printf("%d", count);
    return 0;
}

