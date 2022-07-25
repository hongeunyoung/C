#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode { // ���߿��� ��� Ÿ��
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// ���� ���� ����Ʈ�� �ʱ�ȭ
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// ���� ���� ����Ʈ�� ��带 ���
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

// ���ο� �����͸� ��� before�� �����ʿ� �����Ѵ�. 
void dinsert(DListNode *before, element data) 
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;

	newnode->llink = before;
	before->rlink->llink = newnode;
	newnode->rlink = before->rlink;
	before->rlink = newnode;
}

// ��� removed�� �����Ѵ�. 
void ddelete(DListNode* head, DListNode* removed) 
{
	if (removed == head) return;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);

}

// �������� ��ȸ�ϸ鼭 ����� ������ ���� ���
void print_reverse_dlist(DListNode* head)
{
	DListNode* p;

	for (p = head->llink; p != head; p = p->llink) {
		printf("<-| |%d| |-> ", p->data);
	}

	printf("\n");
}

//data �� ���� ��带 ã�Ƽ� ��ȯ�Ѵ�
DListNode* search(DListNode* head, element data)
{
	DListNode* p;

	for (p = head->rlink; p != head; p = p->rlink)
		if (p->data == data)
			return p;

	return NULL;
}

// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("�߰� �ܰ�\n");

	// �� �տ� ��带 ����
	dinsert(head, 10);
	print_dlist(head);
	dinsert(head, 20);
	print_dlist(head);
	dinsert(head, 30);
	print_dlist(head);

	// �� �ڿ� ��带 �����Ϸ���?
	dinsert(head->llink, 99);
	print_dlist(head);
	
	printf("\n���� �ܰ�\n");

	// �� ���� ��带 ����
	ddelete(head, head->rlink);
	print_dlist(head);

	// �� ���� ��带 �����Ϸ���?
	ddelete(head, head->llink);
	print_dlist(head);

	printf("\n���� ���\n");

	//���� ���
	print_reverse_dlist(head);

	printf("\ndata ã��\n");

	//�����ϴ� data ã��
	printf("data ã��: %d\n", search(head, 20)->data);
	printf("data ã��: %d\n", search(head, 10)->data);

	//�������� �ʴ� data ã��
	if (search(head, 99) == NULL)
		printf("����\n");

	free(head);
	return 0;
}