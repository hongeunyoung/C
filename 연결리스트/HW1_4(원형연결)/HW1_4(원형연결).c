#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { // ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

//����Ʈ ���
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

		printf("%d->", p->data); // ������ ��� ���
	}
	printf("����Ʈ�� ��\n");
}

//ó���� ����
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

	return head; // ����� ��� �����͸� ��ȯ�Ѵ�. 
}

//�������� ����
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

	return head; // ����� ��� �����͸� ��ȯ�Ѵ�. 
} 

ListNode* delete_first(ListNode* head)
{
	ListNode* temp;

	if (head == NULL) {
		printf("����Ʈ�� ��� ������ ����\n");
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
		printf("����Ʈ�� ��� ������ ����\n");
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

// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
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

	printf("��� �˻� ���: %d\n", search(head, 20)->data);

	printf("��� �˻� ���: %d\n", search(head, 30)->data);

	//printf("��� �˻� ���: %d\n", search(head, 40)->data);

	if(search(head, 50) == NULL)
		printf("��� �˻� ���: ����\n");

	printf("��������Ʈ�� ������: %d\n", get_size(head));

	/**/
	return 0;
}