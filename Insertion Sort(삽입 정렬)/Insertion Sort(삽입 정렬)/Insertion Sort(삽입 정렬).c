#include <stdio.h>

insertionSort(int* A, int n) {
	int i;
	int j, k, temp;

	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++)
			if (A[j] > A[i]) break;

		temp = A[i];

		for (k = i; k > j; k--)
			A[k] = A[k - 1];

		A[j] = temp;
	}
}

int main(void) {
	int A[] = { 9, 3, 5, 1, 7, 4 };

	insertionSort(A, 6);

	for (int i = 0; i < 6; i++)
		printf("%d ", A[i]);
}