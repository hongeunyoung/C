#include <stdio.h>
#include <string.h>
#define MAX_STRING 10 //배열을 이용한 스택은 사이즈의 제한이 있다.

//스택을 위한 타입 정의
typedef char element;

typedef struct {
	element data[MAX_STRING];
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
	return(s->top == MAX_STRING - 1);
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
int palindrome(char str[])
{
	StackType s;

	//필요한 변수들 선언
	int i;

	//스택을 초기화하라
	init(&s);

	//str의 문자들을 스택에 넣는다
	for (i = 0; i < strlen(str); i++)
		push(&s, str[i]);

	//스택에서 하나씩 빼면서 str의 문자들과 차례로 비교
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
		printf("palindrome 입니다.\n");
	else
		printf("palindrome 이 아닙니다.\n");
}