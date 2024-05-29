#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

//그래프를 인접 행렬로 표현하기 위한 구조체 정의
typedef struct graphType {
    int n;
    int adjMatrix[MAX_VERTEX][MAX_VERTEX];
}graphType;

//공백 그래프를 생성하는 연산
void createGraph(graphType* g) {
    int i, j;
    g->n = 0; // 정점 개수를 0으로 초기화
    for (i = 0; i < MAX_VERTEX; i++) {
        for (j = 0; j < MAX_VERTEX; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

//그래프 g에 정점 v를 삽입하는 연산
void insertVertex(graphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTEX) {
        printf("\n 그래프 정점의 개수를 초과하였습니다!");
        return;
    }
    g->n++;//그래프 정점의 개수 n을 하나 증가
}

//그래프 g에 간선(u,v)를 삽입하는 연산
void insertEdge(graphType* g, int u, int v) {
    if (u >= g->n || v >= g->n) { //*배열 0부터 시작하는거 생각
        printf("\n 그래프에 없는 정점입니다!");
        return;
    }
    g->adjMatrix[u][v] = 1;
}

//그래프 g의 2차원 배열값을 순서대로 출력하는 연산
void print_adjMatrix(graphType* g) {
    int i, j;
    for (i = 0; i < (g->n); i++) {
        printf("\n\t\t");
        for (j = 0; j < (g->n); j++)
            printf("%2d", g->adjMatrix[i][j]);
    }
}

//void main함수