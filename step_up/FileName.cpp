#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

//�׷����� ���� ��ķ� ǥ���ϱ� ���� ����ü ����
typedef struct graphType {
    int n;
    int adjMatrix[MAX_VERTEX][MAX_VERTEX];
}graphType;

//���� �׷����� �����ϴ� ����
void createGraph(graphType* g) {
    int i, j;
    g->n = 0; // ���� ������ 0���� �ʱ�ȭ
    for (i = 0; i < MAX_VERTEX; i++) {
        for (j = 0; j < MAX_VERTEX; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

//�׷��� g�� ���� v�� �����ϴ� ����
void insertVertex(graphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTEX) {
        printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!");
        return;
    }
    g->n++;//�׷��� ������ ���� n�� �ϳ� ����
}

//�׷��� g�� ����(u,v)�� �����ϴ� ����
void insertEdge(graphType* g, int u, int v) {
    if (u >= g->n || v >= g->n) { //*�迭 0���� �����ϴ°� ����
        printf("\n �׷����� ���� �����Դϴ�!");
        return;
    }
    g->adjMatrix[u][v] = 1;
}

//�׷��� g�� 2���� �迭���� ������� ����ϴ� ����
void print_adjMatrix(graphType* g) {
    int i, j;
    for (i = 0; i < (g->n); i++) {
        printf("\n\t\t");
        for (j = 0; j < (g->n); j++)
            printf("%2d", g->adjMatrix[i][j]);
    }
}

//void main�Լ�