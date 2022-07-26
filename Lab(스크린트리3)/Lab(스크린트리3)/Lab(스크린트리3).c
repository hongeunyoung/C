#define MAX_LEVEL 5
#define MAX_WIDTH 70
int screen[MAX_LEVEL][MAX_WIDTH];
int count = 0;
#include <stdio.h>
void draw_tree(int row, int left, int right)
{
	int mid;

	if (right - left < 2) return;

	mid = (right + left) / 2;

	//순환 이해 테스트 출력)순환의 작동 원리를 파악하기 위해 나중에 아래 문장을 활성화
	printf("**테스트 row=%d left=%d right=%d mid=%d\n", row, left, right, mid);
	printf("	(%d %d)에 x를 찍는다\n", row, mid);

	screen[row][mid] = ++count;
	draw_tree(row + 1, left, mid - 1);//왼쪽영역
	draw_tree(row + 1, mid + 1, right);//오른쪽영역
}

void init(int s[][MAX_WIDTH])
{
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++)
		for (j = 0; j < MAX_WIDTH; j++)
			s[i][j] = '-';
}

void display(int s[][MAX_WIDTH], int width)
{
	int i, j;
	for (i = 0; i < MAX_LEVEL; i++) {
		for (j = 0; j < width; j++)
		{
			if (s[i][j] == '-')
				printf(" %c", s[i][j]);
			else
				printf(" %d", s[i][j]);
		}
		
		printf("\n");
	}
}

int main(void)
{
	int width;

	init(screen);

	printf("Enter a width(<= 70) of a screen:");
	scanf_s("%d", &width);

	draw_tree(0, 0, width - 1);
	display(screen, width);
}