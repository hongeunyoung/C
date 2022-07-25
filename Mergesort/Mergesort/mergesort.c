#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int* A, int p, int q, int r, int *temp) {
	int i = p;
	int j = q + 1;
	int t = 0;

	while (i <= q || j <= r) {
		if (j > r || (j <= r && i <= q && A[i] < A[j])) {
			temp[t] = A[i];
			i++;
		}
		else {
			temp[t] = A[j];
			j++;
		}

		t++;
	}

	for (i = p; i <= r; i++) {
		A[i] = temp[i - p];
	}
}

void merge_sort(int* A, int p, int r, int *temp) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(A, p, q, temp);
		merge_sort(A, q + 1, r, temp);
		merge(A, p, q, r, temp);
	}
}

void printList(int* A, int s, int e) {
	int i;
	for (i = s; i <= e; i++)
		printf("%d ", A[i]);

	printf("\n");
}

int main() {
	int n, i;
	int* data, temp;

	scanf_s("%d", &n);

	data = (int*)malloc(sizeof(int) * n);
	temp = (int*)malloc(sizeof(int) * n);
	srand(time(NULL));

	for (i = 0; i < n; i++)
		data[i] = rand() % 100;

	printList(data, 0, n - 1);
	printf("\n\n");

	merge_sort(data, 0, n - 1, temp);
	printList(data, 0, n - 1);

	free(data);
	free(temp);
}