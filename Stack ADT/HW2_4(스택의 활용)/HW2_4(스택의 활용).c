#include <stdio.h>
#include <string.h>
#define MAX_STRING 10 //�迭�� �̿��� ������ �������� ������ �ִ�.

//������ ���� Ÿ�� ����
typedef char element;

typedef struct {
	element data[MAX_STRING];
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
	return(s->top == MAX_STRING - 1);
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
int palindrome(char str[])
{
	StackType s;

	//�ʿ��� ������ ����
	int i;

	//������ �ʱ�ȭ�϶�
	init(&s);

	//str�� ���ڵ��� ���ÿ� �ִ´�
	for (i = 0; i < strlen(str); i++)
		push(&s, str[i]);

	//���ÿ��� �ϳ��� ���鼭 str�� ���ڵ�� ���ʷ� ��
	for (i = 0; i < strlen(str); i++)
		if (pop(&s) != str[i])
			return 0;

	return 1;
}

int main(void)
{
	char word[MAX_STRING];

	printf("Enter a word to check palindrome: ");
	scanf_s("%s", word, sizeof(word));

	if (palindrome(word))
		printf("palindrome �Դϴ�.\n");
	else
		printf("palindrome �� �ƴմϴ�.\n");
}