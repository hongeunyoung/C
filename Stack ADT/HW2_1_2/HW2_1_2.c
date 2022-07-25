#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 3 //배열을 이용한 스택은 사이즈의 제한이 있다.

//스택을 위한 타입 정의
typedef struct {
	int num;
	char ch[10];
} element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//스택 초기화 함수
void init(StackType* s)
{
	s->top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType* s)
{
	return(s->top == MAX_STACK_SIZE - 1);
}

//삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

//삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

//피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)];
}

//스택 출력 함수
void stack_print(StackType* s)
{
	if (is_empty(s))
		printf("<empty>\n");
	else
		for (int i = s->top; i >= 0; i--) {
			if (i == s->top)
				printf("[%d, %s] <- top\n", s->data[i].num, s->data[i].ch);
			else
				printf("[%d, %s]\n", s->data[i].num, s->data[i].ch);
		}

	printf("--\n");
}

//주함수
int main()
{
	StackType s;
	element e;

	init(&s);
	stack_print(&s);

	e.num = 10;
	strcpy_s(e.ch, sizeof(e.ch), "ten");
	push(&s, e);
	stack_print(&s);

	e.num = 20;
	strcpy_s(e.ch, sizeof(e.ch), "twenty");
	push(&s, e);
	stack_print(&s);

	e.num = 30;
	strcpy_s(e.ch, sizeof(e.ch), "thirty");
	push(&s, e);
	stack_print(&s);

	e.num = 40;
	strcpy_s(e.ch, sizeof(e.ch), "forty");
	push(&s, e);
	stack_print(&s);
	pop(&s);
	stack_print(&s);

	e.num = 50;
	strcpy_s(e.ch, sizeof(e.ch), "fifty");
	push(&s, e);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
}