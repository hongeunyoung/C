//맞는 코든데 비쥬얼 스튜디오 또 지랄이지 아주ㅡㅡ
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int m, int picked[], int toPick)
{
	int smallest, lastIndex, i;

	if (toPick == 0) {
		for (i = 0; i < m; i++)
			printf("%d ", picked[i]);

		printf("\n");

		return;
	}

	lastIndex = m - toPick - 1;

	if (m == toPick)
		smallest = 0;
	else
		smallest = picked[lastIndex] + 1;

	for (i = smallest; i < n; i++) {
		picked[lastIndex + 1] = i;
		pick(n, m, picked, toPick - 1);
	}
}

int main(void) {
	int n, m, *picked;

	printf("Enter n and m:");
	scanf_s("%d %d", &n, &m);

	picked = (int*)malloc(sizeof(int) * m);

	pick(n, m, picked, m);

	free(picked);
}