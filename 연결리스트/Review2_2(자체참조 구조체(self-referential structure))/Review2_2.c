#include <stdio.h>
#include <stdlib.h>

//�� �������� ListNode�� ����ü��
typedef struct ListNode {
	int number;
	struct ListNode* link; //������
} ListNode; //����üŸ��

//�ݺ��� �̿��Ͽ� ��帮��Ʈ�� ���
void displayList1(ListNode* head)
{
	ListNode* temp = head;

	while (temp != NULL) {
		printf("%d->", temp->number);
		temp = temp->link;
	}

	printf("��");
}

//��ȯ�� �̿��Ͽ� ��帮��Ʈ�� ���
void displayList2(ListNode* head)
{
	if (head == NULL) {
		printf("��");
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
		temp = temp->link; //�ϳ� ����
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