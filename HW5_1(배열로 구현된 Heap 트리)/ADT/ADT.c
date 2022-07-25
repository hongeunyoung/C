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

// �ʱ�ȭ �Լ�
void init(HeapType* h)
{
	h->heap_size = 0;
}

// ���� �Լ�: ���� ����� ������ heap_size �� ���� h �� item �� �����Ѵ�.
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

// ���� �Լ�
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

void preorder(HeapType* h, int root) // ����
{
	if (h->heap_size < root)
		return;
	else {
		printf("%d ", h->heap[root]);
		preorder(h, root * 2);
		preorder(h, root * 2 + 1);
	}
}

int find(HeapType* h, int root, int key) // ����
{
	if (root > h->heap_size)
		return 0;
	if (key == h->heap[root].key)
		return root;
	else if (key > h->heap[root].key)
		return 0;
	else
		return max(find(h, root * 2, key), find(h, root * 2 + 1, key));
}

void print_sorted_value(HeapType heap) // delete_max_heap �� �̿��Ѵ�
{
	int i;
	HeapType* h;
	h = (HeapType*)malloc(sizeof(HeapType));
	init(h);
	for (i = 1; i <= heap.heap_size; i++) {
		insert_max_heap(h, heap.heap[i]);
	}

	for (i = 1; i <= heap.heap_size; i++) {
		printf("%d ", delete_max_heap(h).key);
	}

	printf("\n");
	free(h);
}

void print_heap(HeapType* h)
{
	int two = 2;
	for (int i = 1; i <= h->heap_size; i++) {
		if (i == two) {
			printf("\n");
			two *= 2;
		}

		printf("%d ", h->heap[i].key);
	}

	printf("\n");
}

void modify_priority(HeapType* h, int oldkey, int newkey)
{
	int index, child;

	for (int i = 1; i <= h->heap_size; i++) {
		if (h->heap[i].key == oldkey) {
			h->heap[i].key = newkey;
			index = i;
		}
	}

	element item = h->heap[index];
	
	if (item.key > h->heap[index / 2].key) {
		while ((index != 1) && (item.key > h->heap[index / 2].key)) {
			h->heap[index] = h->heap[index / 2];
			index /= 2;
		}
	}
	else {
		child = index * 2;
		while (child <= h->heap_size) {
			// ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
			if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
				child++;
			if (item.key >= h->heap[child].key) break;
			// �Ѵܰ� �Ʒ��� �̵�
			h->heap[index] = h->heap[child];
			index = child;
			child *= 2;
		}
	}
		
	h->heap[index] = item;
}

int main(void)// ���Լ�
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 }, eA = { 9 }, eB = { 19 }, eC = { 39 };
	element e4;
	HeapType heap; // ���� ����
	init(&heap); // �ʱ�ȭ
	// ����
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
	insert_max_heap(&heap, eA);
	insert_max_heap(&heap, eB);
	insert_max_heap(&heap, eC);
	preorder(&heap, 1);
	printf("\n");
	print_heap(&heap);
	// find �Լ� �׽�Ʈ

	// print_sorted_value �Լ� �׽�Ʈ
	print_sorted_value(heap);

	// ����
	e4 = delete_max_heap(&heap);
	printf("\n<%d>\n ", e4.key);
	print_heap(&heap);
	e4 = delete_max_heap(&heap);
	printf("\n<%d>\n ", e4.key);
	print_heap(&heap);
}