#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
#define TRUE 1
#define FALSE 0

typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);
	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // ���ο� ��带 ����
}

element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// �Ѵܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// ���Ͽ��� �о max Heap �� �����Ѵ�.
read_heap(HeapType* h, char* filename) {
	FILE* fs;
	fs = fopen(filename, "r");
	element item;
	char str[10];

	while (feof(fs) == 0) {
		fgets(str, 10, fs);
		item.key = atoi(str);
		insert_max_heap(h, item);
	}

	fclose(fs);
}

//max Heap �� ����� ������ �迭�� ǥ�� �״�� ���Ͽ� ����Ѵ�.
write_heap_array(HeapType* h, char* filename) {
	FILE* fs;
	fs = fopen(filename, "wt");
	for (int i = 1; i <= h->heap_size; i++)
		fprintf(fs, "%d ", h->heap[i].key);

	fclose(fs);
}

// max Heap �� ����� ������ ������������ ���Ͽ� ����Ѵ�.
write_descending_order(HeapType* h, char* filename) {
	FILE* fs;
	fs = fopen(filename, "wt");

	int i;
	HeapType* heap;
	heap = (HeapType*)malloc(sizeof(HeapType));
	init(heap);
	for (i = 1; i <= h->heap_size; i++) {
		insert_max_heap(heap, h->heap[i]);
	}

	for (i = 1; i <= h->heap_size; i++) {
		fprintf(fs, "%d ", delete_max_heap(heap).key);
	}
	free(heap);
	fclose(fs);
}

int main(void)
{
	HeapType heap;
	element e1 = { 20 }, e2 = { 40 };
	init(&heap);
	read_heap(&heap, "input.txt");
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	write_heap_array(&heap, "heapArray.txt");
	write_descending_order(&heap, "sorted.txt");
}