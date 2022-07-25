#include <stdio.h> 
#include <stdlib.h>

typedef int element;

typedef struct ListNode { // 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode* insert_next(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1) 

	p->data = value; //(2) 
	p->link = pre->link; //(3) 
	pre->link = p; //(4) 

	return head; //(5) 
}

//처음에 삽입
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1) 

	p->data = value; // (2) 
	p->link = head; // 헤드 포인터의 값을 복사 //(3) 
	head = p; // 헤드 포인터 변경 //(4) 

	return head; // 변경된 헤드 포인터 반환
}

//마지막에 삽입
ListNode* insert_last(ListNode* head, int value)
{
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1) 

	p->data = value;
	p->link = NULL;

	// (2)
	if (head == NULL) // 공백 리스트이면
		head = p;
	else {
		while (temp->link != NULL)
			temp = temp->link;

		temp->link = p;
	}

	return head; // 변경된 헤드 포인터 반환
}

// pre가 가리키는 노드의 다음 노드를 삭제한다. 
ListNode* delete_next(ListNode *head, ListNode *pre) 
{
	ListNode* removed;

	removed = pre->link;
	pre->link = removed->link; // (2) 
	free(removed); // (3) 

	return head; // (4) 
}

//처음 삭제
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;

	if (head == NULL) error("삭제할 항목이 없음");

	removed = head; // (1) 
	head = removed->link; // (2) 
	free(removed); // (3) 

	return head; // (4) 
}

//마지막 삭제
ListNode* delete_last(ListNode* head)
{
	ListNode* temp = head;
	ListNode* prevTemp = NULL;
	ListNode* removed;

	if (head == NULL) error("삭제할 항목이 없음");

	//if(temp->link == NULL)도 가능
	if (head->link == NULL) { // 하나의 노드
		free(temp);
		head = NULL;
	}
	else { // 둘 이상의 노드
		while (temp->link != NULL) {
			prevTemp = temp;
			temp = temp->link;
		}

		prevTemp->link = NULL;
		free(temp);
	}

	return head;
}

//리스트 출력
void print_list(ListNode* head)
{
	ListNode* p;

	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);

	printf("\n");
}

//x값 탐색
ListNode* search(ListNode* head, int x)
{
	ListNode* p;

	p = head;

	while (p != NULL) {
		if (p->data == x) return p; // 탐색 성공

		p = p->link;
	}

	return NULL; // 탐색 실패일 경우 NULL 반환
}

//연결리스트 2개 연결
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

//리스트 뒤집기
ListNode* reverse(ListNode* head)
{
	// 순회 포인터로 p, q, r을 사용
	ListNode* p, * q, * r;

	p = head; // p는 역순으로 만들 리스트
	q = NULL; // q는 역순으로 만들 노드

	while (p != NULL) {
		r = q; // r은 역순으로 된 리스트. r은 q, q는 p를 차례로 따라간다. 
		q = p ; 
		p = p->link;
		q->link = r; // q의 링크 방향을 바꾼다.
	}

	return q; // q는 역순으로 된 리스트의 헤드 포인터
}

//item 이 리스트에 있으면 1 을 아니면 0 을 반환
int is_in_list(ListNode* head, element item)
{
	ListNode* temp;

	temp = head;

	for (temp = head; temp != NULL; temp = temp->link)
		if (temp->data == item)
			return 1;

	return 0;
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

//단순연결리스트의 모든 데이터 값을 더한 합을 반환
int get_total(ListNode* head)
{
	ListNode* temp;
	int num = 0;

	for (temp = head; temp != NULL; temp = temp->link)
		num += temp->data;

	return num;
}

//pos 위치(0 이 첫 번째 노드)에 있는 노드의 data 를 반환
element get_entry(ListNode* head, int pos)
{
	ListNode* temp;

	temp = head;

	if (pos < 0 || pos >= get_length)
		printf("잘못된 pos");

	for (int i = 0; i < pos; i++)
		temp = temp->link;

	return temp->data;
}

//key값을 찾아서 삭제
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

//pos 위치에 value 를 갖는 노드를 추가
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

//pos 위치의 노드를 삭제
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

	//list1 = 30->20->10->를 만든다. 이때 10, 20, 30의 순으로 노드를 삽입한다. 
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);

	// list1을 출력 
	printf("list1 = ");
	print_list(list1);

	//list1의 맨 앞 노드를 삭제한다 즉, list1 = 20->10-> 
	list1 = delete_first(list1);
	
	// list1을 출력
	printf("list1 = ");
	print_list(list1);
	
	//list2 = 11->22->33->44->를 만든다. 이때 11, 22, 33, 44의 순으로 노드를 삽입한다. 
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);

	// list2를 출력 
	printf("list2 = ");
	print_list(list2);
 
	// list2의 맨 뒤 노드를 삭제한다. 즉, list2 = 11->22->33-> 
	delete_last(list2);
 
	// list2를 출력 
	printf("list2 = ");
	print_list(list2);

	//list2를 역순으로 바꾼 리스트를 list3가 가리키게 한다. list3 = 33->22->11->를 만든다. 
	list3 = reverse(list2);
 
	//list3를 출력한다. 
	printf("list3 = ");
	print_list(list3);
 
	// list1 = 20->10->33->22->11->를 만든다. 즉, list1과 list3를 합쳐서 list1이 가리키게 한다. 
	list1 = concat(list1, list3);
 
	//list1을 출력한다. 
	printf("list1 = ");
	print_list(list1);

	//(A) 주의: 여기서부터는 list1만 사용하여 함수들을 테스트하자 

	printf("----------------------------------------------------\n");
	//list1에 존재하는 20, 33, 11을 넣어 1이 나오는지 확인한다.
	printf("%d\n", is_in_list(list1, 20));
	printf("%d\n", is_in_list(list1, 33));
	printf("%d\n", is_in_list(list1, 11));

	printf("----------------------------------------------------\n");
	//list1에 존재하지 않는 21, 34, 12을 넣어 0이 나오는지 확인한다.
	printf("%d\n", is_in_list(list1, 21));
	printf("%d\n", is_in_list(list1, 34));
	printf("%d\n", is_in_list(list1, 12));

	printf("----------------------------------------------------\n");
	//list1에 존재하는 노드 수 5 반환
	printf("%d\n", get_length(list1));

	printf("----------------------------------------------------\n");
	//list1의 모든 데이터 값을 더한 (20+10+33+22+11=)96 반환
	printf("%d\n", get_total(list1));

	printf("----------------------------------------------------\n");
	//list1의 0, 1, 2, 3, 4번째 위치에 있는 노드 data 반환
	printf("%d\n", get_entry(list1, 0));
	printf("%d\n", get_entry(list1, 1));
	printf("%d\n", get_entry(list1, 2));
	printf("%d\n", get_entry(list1, 3));
	printf("%d\n", get_entry(list1, 4));

	printf("----------------------------------------------------\n");
	//20, 33, 11을 key 값으로 list1에서 삭제하며 list1을 출력해 확인
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
	//list1 0, 2, 4 위치에 20, 33, 11 노드 추가하고 list1을 출력해 확인
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
	//list1 4, 2, 0 위치의 노드를 삭제하고 list1을 출력해 확인
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