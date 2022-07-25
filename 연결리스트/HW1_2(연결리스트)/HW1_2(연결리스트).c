#include <stdio.h> 
#include <stdlib.h>

typedef int element;

typedef struct ListNode { // ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

// ���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert_next(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1) 

	p->data = value; //(2) 
	p->link = pre->link; //(3) 
	pre->link = p; //(4) 

	return head; //(5) 
}

//ó���� ����
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1) 

	p->data = value; // (2) 
	p->link = head; // ��� �������� ���� ���� //(3) 
	head = p; // ��� ������ ���� //(4) 

	return head; // ����� ��� ������ ��ȯ
}

//�������� ����
ListNode* insert_last(ListNode* head, int value)
{
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1) 

	p->data = value;
	p->link = NULL;

	// (2)
	if (head == NULL) // ���� ����Ʈ�̸�
		head = p;
	else {
		while (temp->link != NULL)
			temp = temp->link;

		temp->link = p;
	}

	return head; // ����� ��� ������ ��ȯ
}

// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* delete_next(ListNode *head, ListNode *pre) 
{
	ListNode* removed;

	removed = pre->link;
	pre->link = removed->link; // (2) 
	free(removed); // (3) 

	return head; // (4) 
}

//ó�� ����
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;

	if (head == NULL) error("������ �׸��� ����");

	removed = head; // (1) 
	head = removed->link; // (2) 
	free(removed); // (3) 

	return head; // (4) 
}

//������ ����
ListNode* delete_last(ListNode* head)
{
	ListNode* temp = head;
	ListNode* prevTemp = NULL;
	ListNode* removed;

	if (head == NULL) error("������ �׸��� ����");

	//if(temp->link == NULL)�� ����
	if (head->link == NULL) { // �ϳ��� ���
		free(temp);
		head = NULL;
	}
	else { // �� �̻��� ���
		while (temp->link != NULL) {
			prevTemp = temp;
			temp = temp->link;
		}

		prevTemp->link = NULL;
		free(temp);
	}

	return head;
}

//����Ʈ ���
void print_list(ListNode* head)
{
	ListNode* p;

	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);

	printf("\n");
}

//x�� Ž��
ListNode* search(ListNode* head, int x)
{
	ListNode* p;

	p = head;

	while (p != NULL) {
		if (p->data == x) return p; // Ž�� ����

		p = p->link;
	}

	return NULL; // Ž�� ������ ��� NULL ��ȯ
}

//���Ḯ��Ʈ 2�� ����
ListNode* concat(ListNode* head1, ListNode* head2)
{
	ListNode* p;

	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;

		while (p->link != NULL)
			p = p->link;

		p->link = head2;

		return head1;
	}
}

//����Ʈ ������
ListNode* reverse(ListNode* head)
{
	// ��ȸ �����ͷ� p, q, r�� ���
	ListNode* p, * q, * r;

	p = head; // p�� �������� ���� ����Ʈ
	q = NULL; // q�� �������� ���� ���

	while (p != NULL) {
		r = q; // r�� �������� �� ����Ʈ. r�� q, q�� p�� ���ʷ� ���󰣴�. 
		q = p ; 
		p = p->link;
		q->link = r; // q�� ��ũ ������ �ٲ۴�.
	}

	return q; // q�� �������� �� ����Ʈ�� ��� ������
}

//item �� ����Ʈ�� ������ 1 �� �ƴϸ� 0 �� ��ȯ
int is_in_list(ListNode* head, element item)
{
	ListNode* temp;

	temp = head;

	for (temp = head; temp != NULL; temp = temp->link)
		if (temp->data == item)
			return 1;

	return 0;
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

//�ܼ����Ḯ��Ʈ�� ��� ������ ���� ���� ���� ��ȯ
int get_total(ListNode* head)
{
	ListNode* temp;
	int num = 0;

	for (temp = head; temp != NULL; temp = temp->link)
		num += temp->data;

	return num;
}

//pos ��ġ(0 �� ù ��° ���)�� �ִ� ����� data �� ��ȯ
element get_entry(ListNode* head, int pos)
{
	ListNode* temp;

	temp = head;

	if (pos < 0 || pos >= get_length)
		printf("�߸��� pos");

	for (int i = 0; i < pos; i++)
		temp = temp->link;

	return temp->data;
}

//key���� ã�Ƽ� ����
ListNode* delete_by_key(ListNode* head, int key)
{
	ListNode *temp, *removed = NULL;

	for (temp = head; temp != NULL; temp = temp->link) {
		if (temp->data == key)
			break;

		removed = temp;
	}

	if (removed == NULL)
		head = temp->link;
	else
		removed->link = temp->link;

	return head;
}

//pos ��ġ�� value �� ���� ��带 �߰�
ListNode* insert_pos(ListNode* head, int pos, element value)
{
	ListNode* temp, *p;
	int i;
	p = (ListNode*)malloc(sizeof(ListNode));

	temp = head;

	for (i = 0; i < pos - 1; i++)
		temp = temp->link;

	p->data = value;
	
	if (pos == 0) {
		p->link = temp;
		head = p;
	}
	else {
		p->link = temp->link;
		temp->link = p;
	}
		

	return head;
}

//pos ��ġ�� ��带 ����
ListNode* delete_pos(ListNode* head, int pos)
{
	ListNode* temp, * removed = NULL;

	temp = head;
	for (int i = 0; i < pos; i++) {
		removed = temp;
		temp = temp->link;
	}

	if (removed == NULL)
		head = temp->link;
	else
		removed->link = temp->link;

	free(temp);
	return head;
}

int main(void)
{
	ListNode* list1 = NULL, * list2 = NULL, * list3;

	//list1 = 30->20->10->�� �����. �̶� 10, 20, 30�� ������ ��带 �����Ѵ�. 
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);

	// list1�� ��� 
	printf("list1 = ");
	print_list(list1);

	//list1�� �� �� ��带 �����Ѵ� ��, list1 = 20->10-> 
	list1 = delete_first(list1);
	
	// list1�� ���
	printf("list1 = ");
	print_list(list1);
	
	//list2 = 11->22->33->44->�� �����. �̶� 11, 22, 33, 44�� ������ ��带 �����Ѵ�. 
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);

	// list2�� ��� 
	printf("list2 = ");
	print_list(list2);
 
	// list2�� �� �� ��带 �����Ѵ�. ��, list2 = 11->22->33-> 
	delete_last(list2);
 
	// list2�� ��� 
	printf("list2 = ");
	print_list(list2);

	//list2�� �������� �ٲ� ����Ʈ�� list3�� ����Ű�� �Ѵ�. list3 = 33->22->11->�� �����. 
	list3 = reverse(list2);
 
	//list3�� ����Ѵ�. 
	printf("list3 = ");
	print_list(list3);
 
	// list1 = 20->10->33->22->11->�� �����. ��, list1�� list3�� ���ļ� list1�� ����Ű�� �Ѵ�. 
	list1 = concat(list1, list3);
 
	//list1�� ����Ѵ�. 
	printf("list1 = ");
	print_list(list1);

	//(A) ����: ���⼭���ʹ� list1�� ����Ͽ� �Լ����� �׽�Ʈ���� 

	printf("----------------------------------------------------\n");
	//list1�� �����ϴ� 20, 33, 11�� �־� 1�� �������� Ȯ���Ѵ�.
	printf("%d\n", is_in_list(list1, 20));
	printf("%d\n", is_in_list(list1, 33));
	printf("%d\n", is_in_list(list1, 11));

	printf("----------------------------------------------------\n");
	//list1�� �������� �ʴ� 21, 34, 12�� �־� 0�� �������� Ȯ���Ѵ�.
	printf("%d\n", is_in_list(list1, 21));
	printf("%d\n", is_in_list(list1, 34));
	printf("%d\n", is_in_list(list1, 12));

	printf("----------------------------------------------------\n");
	//list1�� �����ϴ� ��� �� 5 ��ȯ
	printf("%d\n", get_length(list1));

	printf("----------------------------------------------------\n");
	//list1�� ��� ������ ���� ���� (20+10+33+22+11=)96 ��ȯ
	printf("%d\n", get_total(list1));

	printf("----------------------------------------------------\n");
	//list1�� 0, 1, 2, 3, 4��° ��ġ�� �ִ� ��� data ��ȯ
	printf("%d\n", get_entry(list1, 0));
	printf("%d\n", get_entry(list1, 1));
	printf("%d\n", get_entry(list1, 2));
	printf("%d\n", get_entry(list1, 3));
	printf("%d\n", get_entry(list1, 4));

	printf("----------------------------------------------------\n");
	//20, 33, 11�� key ������ list1���� �����ϸ� list1�� ����� Ȯ��
	list1 = delete_by_key(list1, 20);
	printf("list1 = ");
	print_list(list1);

	list1 = delete_by_key(list1, 33);
	printf("list1 = ");
	print_list(list1);

	list1 = delete_by_key(list1, 11);
	printf("list1 = ");
	print_list(list1);

	printf("----------------------------------------------------\n");
	//list1 0, 2, 4 ��ġ�� 20, 33, 11 ��� �߰��ϰ� list1�� ����� Ȯ��
	list1 = insert_pos(list1, 0, 20);
	printf("list1 = ");
	print_list(list1);

	list1 = insert_pos(list1, 2, 33);
	printf("list1 = ");
	print_list(list1);

	list1 = insert_pos(list1, 4, 11);
	printf("list1 = ");
	print_list(list1);

	printf("----------------------------------------------------\n");
	//list1 4, 2, 0 ��ġ�� ��带 �����ϰ� list1�� ����� Ȯ��
	list1 = delete_pos(list1, 4);
	printf("list1 = ");
	print_list(list1);

	list1 = delete_pos(list1, 2);
	printf("list1 = ");
	print_list(list1);

	list1 = delete_pos(list1, 0);
	printf("list1 = ");
	print_list(list1);
} 