#include <stdio.h>

void quickSort(int A[], int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

int partition(int A[], int p, int r) {
	int i = p - 1, j = p;
	int temp;

	while (j < r) {
		if (A[j] < A[r]) {
			i++;

			temp = A[j];

			A[j] = A[i];

			A[i] = temp;
		}

		j++;
	}

	i++;

	temp = A[i];

	A[i] = A[r];

	A[r] = temp;

	return i;
}

int main(void) {
	int A[] = {31, 8, 48, 73, 11, 3, 20, 29, 65, 15};
	
	quickSort(A, 0, 9);

	for (int i = 0; i < 10; i++)
		printf("%d ", A[i]);
}