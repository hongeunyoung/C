#include <stdio.h> 
#include <stdlib.h> 
#include "Review2_1_2.h"

typedef struct score{
	int midterm;
	int final;
} Score;

void printScore(Score* p) {
	printf("�߰���� ������ %d\n", p->midterm);
	printf("�б⸻��� ������ %d\n", p->final);
}

Score* biggerScore(Score* p1, Score* p2) {
	if (p1->midterm + p1->final > p2->midterm + p2->final)
		return p1;
	else
		return p2;
}

Score* totalScore(Score* p1, Score* p2) {
	Score* temp;
	temp = (Score*)malloc(sizeof(Score));
	temp->midterm = p1->midterm + p2->midterm;
	temp->final = p1->final + p2->final;

	return temp;
}

Score* createScore(int m, int f) {
	Score* s = malloc(sizeof(Score));
	s->midterm = m;
	s->final = f;

	return s;
}

int main(void) {
	Score p1, p2;
	Score *p3;

	p3 = (Score*)malloc(sizeof(Score));

	p1.midterm = 50;
	p1.final = 100;

	p2.midterm = 70;
	p2.final = 70;

	printScore(&p1);
	printScore(&p2);

	printf("-----------------------------\n");
	printf("���� ������ ���� ����:\n");
	printScore(biggerScore(&p1, &p2));

	printf("-----------------------------\n");
	printf("�� ������ �� ��:\n");
	printScore(totalScore(&p1, &p2));

	printf("-----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);

	free(p3);
}