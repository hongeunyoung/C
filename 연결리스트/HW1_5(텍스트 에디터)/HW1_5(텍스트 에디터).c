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

//마지막에 삽입
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

//단순 연결 리스트에 존재하는 노드의 수를 반환
int get_length(ListNode* head)
{
	ListNode* temp;
	int num = 0;

	for (temp = head; temp != NULL; temp = temp->link)
		num++;

	return num;
}

//pos 위치(0 이 첫 번째 노드)에 있는 노드의 data 를 반환
element get_entry(ListNode* head, int pos)
{
	ListNode* temp;

	temp = head;

	if (pos < 1 || pos > get_length(head))
		printf("잘못된 라인 번호\n");

	for (int i = 1; i < pos; i++)
		temp = temp->link;

	return temp->data;
}

//pos 위치에 value 를 갖는 노드를 추가
ListNode* insert_pos(ListNode* head, int pos, element* value)
{
	ListNode* temp, * p;
	int i;
	p = (ListNode*)malloc(sizeof(ListNode));

	if (pos < 1 || pos > get_length(head) + 1)
		printf("잘못된 라인 번호\n");
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

//pos 위치의 노드를 삭제
ListNode* delete_pos(ListNode* head, int pos)
{
	ListNode* temp, * removed = NULL;

	if (pos < 1 || pos > get_length(head))
		printf("잘못된 라인 번호\n");
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

//text edited 출력
void display_te(ListNode* head) // text editor 를 위해 변경 // 2)
{
	ListNode* p;

	printf("----------text edited----------\n");

	p = head;

	for (int i = 1; p != NULL; i++) {
		printf("(%d) %s", i, p->data.line);

		p = p->link;
	}
}

//선탤 물어보기
char askChoice(void) {
	char choice;

	printf("------------------------------\n"); 
	printf("a: 텍스트 끝에 라인 추가\n"); 
	printf("i: 라인 번호로 라인 추가\n"); 
	printf("d: 라인 번호로 라인 삭제\n"); 
	printf("v: 라인 번호로 해당 라인 출력\n"); 
	printf("p: 전체 텍스트 출력\n"); 
	printf("q: 끝\n");
	printf("메뉴 선택:"); scanf_s("%c", &choice, 1);

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
			printf("텍스트 끝에 삽입할 라인: ");
			while (getchar() != '\n');
			fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);

			list = insert_last(list, &newElement);
			display_te(list);
			break;
		case 'i':
			printf("삽입할 라인 번호: ");
			scanf_s("%d", &lineNb, sizeof(lineNb));
			printf("삽입할 라인: ");
			while (getchar() != '\n');
			fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);

			list = insert_pos(list, lineNb, &newElement);
			display_te(list);
			break;
		case 'd':
			printf("삭제할 라인 번호: ");
			scanf_s("%d", &lineNb, sizeof(lineNb));

			list = delete_pos(list, lineNb);
			display_te(list);
			while (getchar() != '\n');
			break;
		case 'v':
			printf("출력할 라인 번호: ");
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