#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000L

typedef struct GraphType {
	int n; // ������ ���� 
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; // ������ ����ġ ���� 
} GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

void graph_init(GraphType* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++)
		for (int j = 0; j < MAX_VERTICES; j++)
			g->adj_mat[i][j] = INF;
}
// �ּ� dist[v] ���� ���� ������ ��ȯ
int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i < n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (distance[i] < distance[v])) v = i;
	return (v);
}
//
void prim(GraphType* g, int s)
{
	int i, u, v;

	for (u = 0; u < g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF) return;
		printf("���� %d �߰�\n", u);
		for (v = 0; v < g->n; v++)
			if (g->adj_mat[u][v] != INF)
				if (!selected[v] && g->adj_mat[u][v] < distance[v])
					distance[v] = g->adj_mat[u][v];
	}
}

void read_graph(GraphType * g, char* filename)
{
	int number, u, vm;
	char str[10];
	FILE* fp;
	fp = fopen(filename, "rt");
	if (fp == NULL)
	{
		printf("file %s open error!\n", filename);
		return;
	}

	fscanf(fp, "%d", &g->n);

	while (!feof(fp)) {
		fscanf(fp, "%d %d", &u, &vm);
		insert_edge(g, u, vm);
	}

	fclose(fp);
}

int main(void)
{
	GraphType g, t; // �Է� �׷���, ��� Ʈ�� 
	graph_init(&g);
	read_graph(&g, "input.txt");
	graph_init(&t);
	t.n = g.n;
	kruskal(&g, &t);
	printf("���Ϸ� ���:\n");
	write_graph(&t, "output.txt");
	write_graph(&t, NULL); // to stdout
}