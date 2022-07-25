#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

#define TRUE	1
#define FALSE	0
#define MAX_VERTICES	10	
#define INF 	-1	

int distance[MAX_VERTICES];
int previous[MAX_VERTICES];
int found[MAX_VERTICES];

typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = INF;

	for (r = 0; r < MAX_VERTICES; r++)
		g->adj_mat[r][r] = 0;
}

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void shortest_path(GraphType* g, int k, int test)
{
	int index, sum, min;

	for (int start = 0; start < k; start++) {
		int i, u, w;
		for (i = 0; i < g->n; i++)
		{
			distance[i] = g->adj_mat[start][i];
			found[i] = FALSE;
			previous[i] = start;
		}

		found[start] = TRUE;
		distance[start] = 0;

		sum = 0;
		for (i = 0; i < (g->n) - 1; i++) {
			u = choose(distance, g->n, found);
			found[u] = TRUE;

			printf("%d", distance[u]);
			if(distance[u] != INF)
				sum += distance[u];

			for (w = 0; w < g->n; w++) {
				if (!found[w])
					if (distance[u] + g->adj_mat[u][w] < distance[w]) {
						distance[w] = distance[u] + g->adj_mat[u][w];
						previous[w] = u;
					}
			}
		}

		if (start == 0) {
			index = 0;
			min = sum;
		}
		else if (sum < min) {
			min = sum;
			index = start;
		}
	}

	printf("#%d %d %d\n", test, index, min);
}

int main()
{
	int test, n, u = 0, v = 0;
	GraphType g;
	graph_init(&g);

	scanf_s("%d", &test);

	for (int i = 0; i < test; i++) {
		scanf_s("%d", &n);
		g.n = n;

		for (int j = 0; j < n; j++) {
			scanf_s("%d", &u);
			scanf_s("%d", &v);
			scanf_s("%d", &g.adj_mat[u][v]);
			g.adj_mat[v][u] = g.adj_mat[u][v];
		}

		shortest_path(&g, n, (i + 1));
	}
}
