#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 3 //�迭�� �̿��� ������ �������� ������ �ִ�.

//������ ���� Ÿ�� ����
typedef struct {
	int num;
	char ch[10];
} element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//���� �ʱ�ȭ �Լ�
void init(StackType* s)
{
	s->top = -1;
}

//���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}

//��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return(s->top == MAX_STACK_SIZE - 1);
}

//�����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

//�����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

//��ũ�Լ�
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[(s->top)];
}

//���� ��� �Լ�
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

//���Լ�
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