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

//�ʱ�ȭ �Լ�
void init(QueueType* q)
{
	q->front = q->rear = 0;
}

//���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return q->front == q->rear;
}

//��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		printf("����ڰ� ��á���� ���ȸ�� �̿�...\n");
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->queue[q->rear] = item;
	}
}

//���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

//������ �Լ�
element peek(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

//���� COUNT
int get_count(QueueType* q)
{
	return q->rear - q->front;
}

//���
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

//�� �Լ�
void main()
{
	QueueType manQ;
	QueueType womanQ;
	element newPerson;
	char choice;

	init(&manQ);

	printf("���� �ּ� ���α׷��Դϴ�.\n");
	printf("i<nsert, ���Է�>, c<heck, ����� üũ>,q<uit>:");
	scanf_s("%c", &choice, sizeof(choice));

	while (choice != 'q') {
		if (choice == 'i') {
			printf("�̸��� �Է�:");
			scanf_s("%s", newPerson.name, sizeof(newPerson.name));

			getchar();

			printf("������ �Է�<m or f>:");
			scanf_s("%c", &newPerson.sex, sizeof(newPerson.sex));
			
			if (newPerson.sex == 'm') {
				if (is_empty(&womanQ)) {
					printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
					enqueue(&manQ, newPerson);
				}
				else
					printf("Ŀ���� ź���߽��ϴ�! %s�� %s", dequeue(&womanQ).name, newPerson.name);
			}
			else if (newPerson.sex == 'f') {
				if (is_empty(&manQ)) {
					printf("���� ����ڰ� �����ϴ�.");
					enqueue(&womanQ, newPerson);
				}
				else
					printf("Ŀ���� ź���߽��ϴ�! %s�� %s\n", newPerson.name, dequeue(&manQ).name);
			}
		}
		else if (choice == 'c') {
			printf("���� ����� %d��: ", get_count(&manQ));
			print_queue(&manQ);

			printf("���� ����� %d��: ", get_count(&womanQ));
			print_queue(&womanQ);
		}

		getchar();

		printf("i<nsert, ���Է�>, c<heck, ����� üũ>,q<uit>:");
		scanf_s("%c", &choice, sizeof(choice));
	} 
}