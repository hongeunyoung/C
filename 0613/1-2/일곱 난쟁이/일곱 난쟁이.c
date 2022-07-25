#include <stdio.h>
#include <stdlib.h>

//오름차순으로 정렬할 때 사용하는 비교 함수
int static compare(const void* first, const void* second) {
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main() {
    int n[9];
    int total;

    for (int i = 0; i < 9; i++)
        scanf_s("%d", &n[i]);

    qsort(n, 9, sizeof(int), compare);

    for (int i = 0; i < 8; i++) {
        for (int j = (i + 1); j < 9; j++) {
            total = 0;
            for (int k = 0; k < 9; k++) {
                if (k != i && k != j) {
                    total += n[k];
                }
            }

            if (total == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j) {
                        printf("%d\n", n[k]);
                    }
                }

                return 0;
            }
        }
    }
}