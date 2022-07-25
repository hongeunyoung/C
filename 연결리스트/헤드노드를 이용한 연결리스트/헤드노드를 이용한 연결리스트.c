#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode { // 노드 타입
	int num;
	struct ListNode* link;
} ListNode;

// 연결 리스트 헤더
typedef struct ListType { // 리스트 헤더 타입
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 리스트 헤더 생성 함수
ListType* create()
{
	ListType* plist = (ListType*)malloc(sizeof(ListType)); 
	
	return plist;
}

// plist는 연결 리스트의 헤더를 가리키는 포인터
void insert_last(ListType* plist, int n)
{
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));

	if (temp == NULL) error("메모리 할당 에러");

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

	// 연결 리스트 헤더 생성
	list = create();

	insert_last(list, 33);
	insert_last(list, 22);
	insert_last(list, 11);

	// 연산 테스트를 위한 코드 작성
	free(list);
}