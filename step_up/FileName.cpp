#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define N 10

struct list_node {
	int vertex;
	int weight;
	struct list_node* link;
};

typedef struct list_node node;
typedef node* node_ptr;
node_ptr graph[N];
int visited[N];
/* Matrix �������, ��ΰ� ������ 0, ��ΰ� ������ ��� ���� �� */
int matrix[N][N] = { { 0,1,1,0,1,0,1,0,0,0 },       { 1,0,0,0,0,0,0,0,0,0 },        { 1,0,0,1,0,0,0,0,1,0 },       { 0,0,1,0,0,1,0,1,0,0 },
{ 1,0,0,0,0,0,0,0,0,0 },      { 0,0,0,1,0,0,0,0,0,1 },      { 1,0,0,0,0,0,0,1,0,0 },     { 0,0,0,1,0,0,1,0,0,0 },     { 0,0,1,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,1,0,0,0,0 },
};
/* create �Լ��� ��������� ��������Ʈ�� ��ȯ�Ѵ� */
void create()
{
	int i, j;
	node_ptr temp;
	for (i = 0; i < 10; i++)
		for (j = N - 1; j >= 0; j--)
		{
			if (matrix[i][j] != 0)
			{
				temp = (node_ptr)malloc(sizeof(node));
				temp->link = graph[i];
				temp->weight = matrix[i][j];
				temp->vertex = j;
				graph[i] = temp;
			}
		}
}
void dfs(int v)
{
	node_ptr  w;
	visited[v] = TRUE; /* 1 �湮�� ǥ�� */
	printf("%5d", v);
	for (w = graph[v]; w; w = w->link) /* 2 ���Ḯ��Ʈ Ž�� */
		if (!visited[w->vertex])
			dfs(w->vertex);
}
void main()
{
	int i;
	node_ptr temp;
	/* �ʱ�ȭ �۾� */
	for (i = 0; i < 10; i++) { graph[i] = NULL; visited[i] = FALSE; }
	create();
	printf(" * ���Ḯ��Ʈ ���� ��� * \n");
	for (i = 0; i < 10; i++)
	{
		printf("* %dth node = ", i);
		temp = graph[i];
		while (temp) { printf(" %d", temp->vertex);  temp = temp->link; };
		printf("\n");
	}
	/* dfs Ž��, 3�� ������ �����غ��� */
	printf(" \n * DFS Traversal is = ");
	dfs(3);
	printf(" end of  DFS Traversal\n");
}
