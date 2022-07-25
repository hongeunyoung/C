#include <stdio.h> 
#include <malloc.h> 

// 스택을 위한 타입 정의 
typedef int element;

typedef struct {
	int num;
	char ch[10];
} element2;

typedef struct StackNode {
	element item;
	struct StackNode* link;
} StackNode;

typedef struct StackNode2 {
	element2 item;
	struct StackNode* link;
} StackNode2;

typedef struct {
	StackNode* top;
} LinkedStackType;

typedef struct {
	StackNode2* top;
} LinkedStackType2;

// 초기화 함수
void init(LinkedStackType* s)
{
	s->top = NULL;
}

// 공백 상태 검출 함수 
int is_empty(LinkedStackType* s)
{
	return s->top == NULL;
}

// 포화 상태 검출 함수 
int is_full(LinkedStackType* s) // Stack 연산중의 하나라 남겨두었지만 항상 거짓을 반환. 즉 꽉 차있을 때는 없음 
{
	return 0;
}

// 삽입 함수 
void push(LinkedStackType* s, element item)
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}

void push2(LinkedStackType2* s, element2 item)
{
	StackNode2* temp = (StackNode2*)malloc(sizeof(StackNode2));

	if (temp == NULL) {
		fprintf(stderr, "메모리 할당에러\n");
		return;
	}
	else {
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}

// 삭제 함수 
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		element item = temp->item;

		s->top = s->top->link;
		free(temp);
		return item;
	}
}

element2 pop2(LinkedStackType2* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode2* temp = s->top;
		element2 item = temp->item;

		s->top = s->top->link;
		free(temp);
		return item;
	}
}

// 피크 함수 
element peek(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}

//HW2_2_1
void  stack_print(LinkedStackType* s) 
{
	StackNode* temp = s->top;

	if (temp == NULL)
		printf("<empty>\n");
	else {
		while (temp != NULL) {
			if (temp == s->top)
				printf("%d <- top\n", temp->item);
			else
				printf("%d\n", temp->item);

			temp = temp->link;
		}
	}

	printf("--\n");

	free(temp);
	return;
}

//HW2_2_2
void  stack_print2(LinkedStackType2* s)
{
	StackNode2* temp = s->top;

	if (temp == NULL)
		printf("<empty>\n");
	else {
		while (temp != NULL) {
			if (temp == s->top)
				printf("[%d, %s] <- top\n", temp->item.num, temp->item.ch);
			else
				printf("[%d, %s]\n", temp->item.num, temp->item.ch);

			temp = temp->link;
		}
	}

	printf("--\n");

	free(temp);
	return;
}

// 주 함수 
void main()
{
	LinkedStackType s, s1, s2;
	element2 e;

	init(&s);
	init(&s1);
	init(&s2);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", is_empty(&s));

	//HW2_1_1과의 차이점: 배열처럼 지정된 크기가 없기 때문에 스택 포화 에러가 발생하지 않는다.
	printf("\nHW2_2_1\n");

	stack_print(&s1);

	push(&s1, 10);
	stack_print(&s1);

	push(&s1, 20);
	stack_print(&s1);

	push(&s1, 30);
	stack_print(&s1);

	push(&s1, 40);
	stack_print(&s1);

	pop(&s1);
	stack_print(&s1);

	push(&s1, 50);
	stack_print(&s1);

	pop(&s1);
	stack_print(&s1); 
	
	pop(&s1);
	stack_print(&s1); 
	
	pop(&s1);
	stack_print(&s1);

	printf("\nHW2_2_2\n");
	e.num = 10;
	strcpy_s(e.ch, sizeof(e.ch), "ten");
	push2(&s2, e);
	stack_print2(&s2);

	e.num = 20;
	strcpy_s(e.ch, sizeof(e.ch), "twenty");
	push2(&s2, e);
	stack_print2(&s2);

	e.num = 30;
	strcpy_s(e.ch, sizeof(e.ch), "thirty");
	push2(&s2, e);
	stack_print2(&s2);

	e.num = 40;
	strcpy_s(e.ch, sizeof(e.ch), "forty");
	push2(&s2, e);
	stack_print2(&s2);
	pop2(&s2);
	stack_print2(&s2);

	e.num = 50;
	strcpy_s(e.ch, sizeof(e.ch), "fifty");
	push2(&s2, e);
	stack_print2(&s2);
	pop2(&s2);
	stack_print2(&s2);
	pop2(&s2);
	stack_print2(&s2);
	pop2(&s2);
	stack_print2(&s2);
}