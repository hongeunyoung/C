#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#define MAX_CHAR_PER_LINE 100

typedef struct {
	char line[MAX_CHAR_PER_LINE];
} element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

//�������� ����
ListNode* insert_last(ListNode* head, element* value)
{
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1) 

	strcpy_s(p->data.line, MAX_CHAR_PER_LINE, value->line);
	p->link = NULL;

	if (head == NULL)
		head = p;
	else {
		while (temp->link != NULL)
			temp = temp->link;

		temp->link = p;
	}

	return head;
}

//�ܼ� ���� ����Ʈ�� �����ϴ� ����� ���� ��ȯ
int get_length(ListNode* head)
{
	ListNode* temp;
	int num = 0;

	for (temp = head; temp != NULL; temp = temp->link)
		num++;

	return num;
}

//pos ��ġ(0 �� ù ��° ���)�� �ִ� ����� data �� ��ȯ
element get_entry(ListNode* head, int pos)
{
	ListNode* temp;

	temp = head;

	if (pos < 1 || pos > get_length(head))
		printf("�߸��� ���� ��ȣ\n");

	for (int i = 1; i < pos; i++)
		temp = temp->link;

	return temp->data;
}

//pos ��ġ�� value �� ���� ��带 �߰�
ListNode* insert_pos(ListNode* head, int pos, element* value)
{
	ListNode* temp, * p;
	int i;
	p = (ListNode*)malloc(sizeof(ListNode));

	if (pos < 1 || pos > get_length(head) + 1)
		printf("�߸��� ���� ��ȣ\n");
	else {
		strcpy_s(p->data.line, MAX_CHAR_PER_LINE, value->line);

		if (pos == 1) {
			p->link = head;
			head = p;
		}
		else {
			temp = head;

			for (i = 1; i < pos - 1; i++)
				temp = temp->link;

			p->link = temp->link;
			temp->link = p;
		}
	}

	return head;
}

//pos ��ġ�� ��带 ����
ListNode* delete_pos(ListNode* head, int pos)
{
	ListNode* temp, * removed = NULL;

	if (pos < 1 || pos > get_length(head))
		printf("�߸��� ���� ��ȣ\n");
	else {
		temp = head;

		for (int i = 1; i < pos; i++) {
			removed = temp;
			temp = temp->link;
		}

		if (removed == NULL)
			head = temp->link;
		else
			removed->link = temp->link;

		free(temp);
	}
	
	return head;
}

//text edited ���
void display_te(ListNode* head) // text editor �� ���� ���� // 2)
{
	ListNode* p;

	printf("----------text edited----------\n");

	p = head;

	for (int i = 1; p != NULL; i++) {
		printf("(%d) %s", i, p->data.line);

		p = p->link;
	}
}

//���� �����
char askChoice(void) {
	char choice;

	printf("------------------------------\n"); 
	printf("a: �ؽ�Ʈ ���� ���� �߰�\n"); 
	printf("i: ���� ��ȣ�� ���� �߰�\n"); 
	printf("d: ���� ��ȣ�� ���� ����\n"); 
	printf("v: ���� ��ȣ�� �ش� ���� ���\n"); 
	printf("p: ��ü �ؽ�Ʈ ���\n"); 
	printf("q: ��\n");
	printf("�޴� ����:"); scanf_s("%c", &choice, 1);

	return choice;
}

int main(void)
{
	ListNode* list = NULL;
	char choice;
	int lineNb;
	element newElement;;

	while ((choice = askChoice()) != 'q') {
		switch (choice) {
		case 'a':
			printf("�ؽ�Ʈ ���� ������ ����: ");
			while (getchar() != '\n');
			fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);

			list = insert_last(list, &newElement);
			display_te(list);
			break;
		case 'i':
			printf("������ ���� ��ȣ: ");
			scanf_s("%d", &lineNb, sizeof(lineNb));
			printf("������ ����: ");
			while (getchar() != '\n');
			fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);

			list = insert_pos(list, lineNb, &newElement);
			display_te(list);
			break;
		case 'd':
			printf("������ ���� ��ȣ: ");
			scanf_s("%d", &lineNb, sizeof(lineNb));

			list = delete_pos(list, lineNb);
			display_te(list);
			while (getchar() != '\n');
			break;
		case 'v':
			printf("����� ���� ��ȣ: ");
			scanf_s("%d", &lineNb, sizeof(lineNb));

			printf("(%d) %s", lineNb, get_entry(list, lineNb).line);
			while (getchar() != '\n');
			break;
		case 'p':
			display_te(list);
			while (getchar() != '\n');
		}
		fflush(stdin);
	}
}