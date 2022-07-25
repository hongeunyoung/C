#include <stdio.h>
#include <stdlib.h>

//이 시점에서 ListNode는 구조체명
typedef struct ListNode {
	int number;
	struct ListNode* link; //포인터
} ListNode; //구조체타입

//반복을 이용하여 노드리스트를 출력
void displayList1(ListNode* head)
{
	ListNode* temp = head;

	while (temp != NULL) {
		printf("%d->", temp->number);
		temp = temp->link;
	}

	printf("끝");
}

//순환을 이용하여 노드리스트를 출력
void displayList2(ListNode* head)
{
	if (head == NULL) {
		printf("끝");
		return;
	}

	printf("%d->", head->number);
	displayList2(head->link);
}

int main(void)
{
	ListNode* head, * newNode, * temp;

	//1
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 10;
	newNode->link = NULL;
	head = newNode;

	//2
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 20;
	newNode->link = NULL;
	head->link = newNode;

	//3
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 30;
	newNode->link = NULL;
	head->link->link = newNode;

	//4
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 44;
	newNode->link = NULL;
	temp = head;

	while (temp->link != NULL) {
		temp = temp->link; //하나 전진
	}

	temp->link = newNode;

	//5
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->number = 1;
	newNode->link = head;
	head = newNode;

	//6, 7
	displayList1(head);
	printf("\n");
	displayList2(head);
}