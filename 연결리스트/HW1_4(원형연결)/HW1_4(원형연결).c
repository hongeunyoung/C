#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { // 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

//리스트 출력
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;

	if (head->link == head)
		printf("%d->", head->data);
	else {
		p = head->link;
		do {
			printf("%d->", p->data);
			p = p->link;
		} while (p != head);

		printf("%d->", p->data); // 마지막 노드 출력
	}
	printf("리스트의 끝\n");
}

//처음에 삽입
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	
	if (head == NULL) {
		head = node;
		head->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}

	return head; // 변경된 헤드 포인터를 반환한다. 
}

//마지막에 삽입
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL) {
		head = node;
		head->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}

	return head; // 변경된 헤드 포인터를 반환한다. 
} 

ListNode* delete_first(ListNode* head)
{
	ListNode* temp;

	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n");
		return NULL;
	}

	if (head->link == head) {
		free(head);
		head == NULL;
	}
	else {
		temp = head->link;
		head->link = temp->link;
		free(temp);
	}

	return head;
}

ListNode* delete_last(ListNode* head) 
{
	ListNode* temp = NULL;

	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n");
		return NULL;
	}

	if (head->link == head) {
		free(head);
		head = NULL;
	}
	else {
		for (temp = head; temp->link != head; temp = temp->link);

		temp->link = head->link;
		head = temp;
	}

	return head;
}

ListNode* search(ListNode* head, element data)
{
	ListNode* temp;

	temp = head->link;

	do {
		if (temp->data == data)
			return temp;

		temp = temp->link;			
	} while (temp != head->link);

	return NULL;
}

int get_size(ListNode* head)
{
	int size = 0;
	ListNode* temp;

	temp = head->link;

	do {
		size++;

		temp = temp->link;
	} while (temp != head->link);

	return size;
}

// 원형 연결 리스트 테스트 프로그램
int main(void)
{
	ListNode* head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	print_list(head);

	head = insert_last(head, 30);
	print_list(head);

	head = insert_last(head, 40);
	print_list(head);

	head = insert_first(head, 10);
	print_list(head);

	head = delete_first(head);
	print_list(head);

	head = delete_last(head);
	print_list(head);

	printf("노드 검색 결과: %d\n", search(head, 20)->data);

	printf("노드 검색 결과: %d\n", search(head, 30)->data);

	//printf("노드 검색 결과: %d\n", search(head, 40)->data);

	if(search(head, 50) == NULL)
		printf("노드 검색 결과: 없다\n");

	printf("원형리스트의 사이즈: %d\n", get_size(head));

	/**/
	return 0;
}