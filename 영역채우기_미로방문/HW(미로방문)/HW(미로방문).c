#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10
int count = 0;
int screen[WIDTH][HEIGHT] = {
	0, 0, 0, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, 0, -1, -1, -1, -1, -1, -1, -1,
	-1, 0, 0, 0, 0, 0, 0, -1, -1, -1,
	-1, -1, -1, -1, 0, -1, 0, -1, -1, -1,
	-1, -1, -1, -1, 0, -1, 0, -1, -1, -1,
	-1, -1, 0, 0, 0, -1, 0, 0, 0, -1,
	-1, -1, -1, -1, 0, -1, 0, -1, -1, -1,
	-1, -1, -1, -1, 0, -1, 0, -1, 0, -1,
	-1, -1, -1, -1, 0, -1, -1, -1, 0, -1,
	-1, -1, -1, -1, 0, 0, 0, 0, 0, 0
};

void flood_fill(int x, int y)
{
	if (screen[x][y] == 0 && x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
	{
		screen[x][y] = ++count;

		flood_fill(x, y + 1); //��ȯ ȣ��
		flood_fill(x + 1, y); //��ȯ ȣ��
		flood_fill(x, y - 1); //��ȯ ȣ��
		flood_fill(x - 1, y); //��ȯ ȣ��
	}
}

int main(void)
{
	int i, j;

	printf("�̷�\n");
	for (i = 0; i < WIDTH; i++)
	{
		for (j = 0; j < HEIGHT; j++)
			printf("%3d", screen[i][j]);

		printf("\n");
	}

	printf("\n�������� <0 0>���� �� �̷ι湮<����ǥ��>\n");
	flood_fill(0, 0);

	for (i = 0; i < WIDTH; i++)
	{
		for (j = 0; j < HEIGHT; j++)
			printf("%3d", screen[i][j]);

		printf("\n");
	}
}