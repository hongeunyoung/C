#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode { // ��� Ÿ��
	int num;
	struct ListNode* link;
} ListNode;

// ���� ����Ʈ ���
typedef struct ListType { // ����Ʈ ��� Ÿ��
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ����Ʈ ��� ���� �Լ�
ListType* create()
{
	ListType* plist = (ListType*)malloc(sizeof(ListType)); 
	
	return plist;
}

// plist�� ���� ����Ʈ�� ����� ����Ű�� ������
void insert_last(ListType* plist, int n)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));

	if (temp == NULL) error("�޸� �Ҵ� ����");

	temp->num = n;
	temp->link = NULL;
}

void insert_first(ListType* plist, int value)
{

}

void delete_first(ListType* plist)
{

}

void delete_last(ListType* plist)
{

}

void print_list(ListType* plist)
{
	for (ListNode* p = plist->head; p != NULL; p = p->link)
		printf("%d->", p->num);

	printf("NULL \n");
}

int main(void)
{
	ListType* list;

	// ���� ����Ʈ ��� ����
	list = create();

	insert_last(list, 33);
	insert_last(list, 22);
	insert_last(list, 11);

	// ���� �׽�Ʈ�� ���� �ڵ� �ۼ�
	free(list);
}