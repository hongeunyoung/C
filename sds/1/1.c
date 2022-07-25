#include<stdio.h>
#include<stdlib.h>

int add(int* data, int end) {
    int sum = 0;
    for (int i = 0; i < end; i++)
        sum += data[i];

    return sum;
}

int static compare(const void* first, const void* second)
{
    if (*(int*)first < *(int*)second)
        return 1;
    else if (*(int*)first > *(int*)second)
        return -1;
    else
        return 0;
}

int main() {
    int test, cs;
    int card[20][10000];

    scanf("%d", &test);
    for (int i = 0; i < test; i++)
    {

        scanf("%d", &cs);
        for (int j = 0; j < cs; j++)
            scanf("%d", &card[i][j]);

        qsort(card[i], cs, sizeof(int), compare);
        printf("#%d %d\n", (i + 1), add(card[i], cs / 2));
    }
    return 0;
}