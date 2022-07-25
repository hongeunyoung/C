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

// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}

// 삽입 함수: 현재 요소의 개수가 heap_size 인 히프 h 에 item 을 삽입한다.
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);
	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // 새로운 노드를 삽입
}

// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent = 1, child = 2;
	element item = h->heap[1];
	element temp = h->heap[(h->heap_size)--];

	while (child <= h->heap_size) {
		// 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// 한단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void preorder(HeapType* h, int root) // 숙제
{
	if (h->heap_size < root)
		return;
	else {
		printf("%d ", h->heap[root]);
		preorder(h, root * 2);
		preorder(h, root * 2 + 1);
	}
}

int find(HeapType* h, int root, int key) // 숙제
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

void print_sorted_value(HeapType heap) // delete_max_heap 을 이용한다
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

	index = find(h, 1, oldkey);
	h->heap[index].key = newkey;

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
			// 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
			if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
				child++;
			if (item.key >= h->heap[child].key) break;
			// 한단계 아래로 이동
			h->heap[index] = h->heap[child];
			index = child;
			child *= 2;
		}
	}

	h->heap[index] = item;
}

int main(void)
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 }, eA = { 9 }, eB = { 19 }, eC = { 39 };
	element e4, e5, e6;
	int index;
	int key, oldKey, newKey;
	HeapType heap; // 히프 생성 
	init(&heap); // 초기화 
	printf("Step1: 삽입된 10, 5, 30 에 추가적으로 9, 19, 39 를 <삽입> 한다");
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);
	insert_max_heap(&heap, eA);
	insert_max_heap(&heap, eB);
	insert_max_heap(&heap, eC);
	printf("\nStep2: preorder, print_heap 함수 테스트\n");
	preorder(&heap, 1);
	printf("\n\n");
	print_heap(&heap);
	e4 = delete_max_heap(&heap);
	printf("\n%d 삭제: 루트가 삭제됨\n", e4.key);
	print_heap(&heap);
	printf("\nStep3: find 함수 테스트\n");
	printf("찾을 key 입력(-1 for exit):");
	scanf_s("%d", &key, sizeof(key));
	while (key != -1) {
		if ((index = find(&heap, 1, key)) == 0)
			printf("%d 는 없음\n", key);
		else
			printf("%d 은 [%d]에 있음\n", key, index);
		printf("찾을 key 입력(-1 for exit):");
		scanf_s("%d", &key, sizeof(key));
	}
	printf("\nStep4: print_sorted_value 함수 테스트\n");
	print_sorted_value(heap);
	printf("\nStep5: modify_priority 함수 테스트\n");
	printf("바꿀 key 입력(-1 for exit):");
	scanf_s("%d", &oldKey);
	while (oldKey != -1) {
		printf("새 key 입력:");
		scanf_s("%d", &newKey);
		modify_priority(&heap, oldKey, newKey);
		print_heap(&heap);
		printf("바꿀 key 입력(-1 for exit):");
		scanf_s("%d", &oldKey);
	}
}