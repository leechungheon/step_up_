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
/* Matrix 인접행렬, 경로가 없으면 0, 경로가 있으면 경로 길이 값 */
int matrix[N][N] = { { 0,1,1,0,1,0,1,0,0,0 },       { 1,0,0,0,0,0,0,0,0,0 },        { 1,0,0,1,0,0,0,0,1,0 },       { 0,0,1,0,0,1,0,1,0,0 },
{ 1,0,0,0,0,0,0,0,0,0 },      { 0,0,0,1,0,0,0,0,0,1 },      { 1,0,0,0,0,0,0,1,0,0 },     { 0,0,0,1,0,0,1,0,0,0 },     { 0,0,1,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,1,0,0,0,0 },
};
/* create 함수는 인접행렬을 인접리스트로 변환한다 */
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
	visited[v] = TRUE; /* 1 방문지 표시 */
	printf("%5d", v);
	for (w = graph[v]; w; w = w->link) /* 2 연결리스트 탐색 */
		if (!visited[w->vertex])
			dfs(w->vertex);
}
void main()
{
	int i;
	node_ptr temp;
	/* 초기화 작업 */
	for (i = 0; i < 10; i++) { graph[i] = NULL; visited[i] = FALSE; }
	create();
	printf(" * 연결리스트 내용 출력 * \n");
	for (i = 0; i < 10; i++)
	{
		printf("* %dth node = ", i);
		temp = graph[i];
		while (temp) { printf(" %d", temp->vertex);  temp = temp->link; };
		printf("\n");
	}
	/* dfs 탐색, 3번 노드부터 시작해본다 */
	printf(" \n * DFS Traversal is = ");
	dfs(3);
	printf(" end of  DFS Traversal\n");
}
