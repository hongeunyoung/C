#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3

typedef struct {
	char sex;
	char name[10];
} element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

//
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화 함수
void init(QueueType* q)
{
	q->front = q->rear = 0;
}

//공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return q->front == q->rear;
}

//포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		printf("대기자가 꽉찼으니 담기회를 이용...\n");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->queue[q->rear] = item;
	}
}

//삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

//엿보기 함수
element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

//내용 COUNT
int get_count(QueueType* q)
{
	return q->rear - q->front;
}

//출력
void print_queue(QueueType* q)
{
	if (!is_empty(q)) {
		int i = q->front;

		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%s ", &q->queue[i].name);

			if (i == q->rear)
				break;
		} while (i != q->front);
	}

	printf("\n");
	return;
}

//주 함수
void main()
{
	QueueType manQ;
	QueueType womanQ;
	element newPerson;
	char choice;

	init(&manQ);

	printf("미팅 주선 프로그램입니다.\n");
	printf("i<nsert, 고객입력>, c<heck, 대기자 체크>,q<uit>:");
	scanf_s("%c", &choice, sizeof(choice));

	while (choice != 'q') {
		if (choice == 'i') {
			printf("이름을 입력:");
			scanf_s("%s", newPerson.name, sizeof(newPerson.name));

			getchar();

			printf("성별을 입력<m or f>:");
			scanf_s("%c", &newPerson.sex, sizeof(newPerson.sex));
			
			if (newPerson.sex == 'm') {
				if (is_empty(&womanQ)) {
					printf("아직 대상자가 없습니다. 기다려주십시요.\n");
					enqueue(&manQ, newPerson);
				}
				else
					printf("커플이 탄생했습니다! %s과 %s", dequeue(&womanQ).name, newPerson.name);
			}
			else if (newPerson.sex == 'f') {
				if (is_empty(&manQ)) {
					printf("아직 대상자가 없습니다.");
					enqueue(&womanQ, newPerson);
				}
				else
					printf("커플이 탄생했습니다! %s과 %s\n", newPerson.name, dequeue(&manQ).name);
			}
		}
		else if (choice == 'c') {
			printf("남성 대기자 %d명: ", get_count(&manQ));
			print_queue(&manQ);

			printf("여성 대기자 %d명: ", get_count(&womanQ));
			print_queue(&womanQ);
		}

		getchar();

		printf("i<nsert, 고객입력>, c<heck, 대기자 체크>,q<uit>:");
		scanf_s("%c", &choice, sizeof(choice));
	} 
}