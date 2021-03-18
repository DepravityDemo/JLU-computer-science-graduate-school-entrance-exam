#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAXN = 100;
struct ArcNode {
	int adjvex;
	ArcNode* nextarc;
};



struct Vnode {
	int data;
	ArcNode* firstarc;
};
struct graph
{
	Vnode adjlist[MAXN];
	int n, e;
};

graph *g = (graph*)malloc(sizeof(graph));
void creatgraph(graph *g) {
	int i, j;
	printf("n,e = ");
	scanf("%d %d", &g->n, &g->e);
	printf("Please input jd informatin: ");
	for (int k = 1; k <= g->n; k++) {
		g->adjlist[k].data = k;
		g->adjlist[k].firstarc = NULL;
	}
	printf("Please input the from and to: ");
	for (int k = 1; k <= g->e; k++) {
		ArcNode * p;
		scanf("%d %d", &i, &j);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = g->adjlist[i].firstarc;
		g->adjlist[i].firstarc = p;

		/*

		/*
				for (int k = 1; k <=g->n; k++) {
					printf("%d  ", g->adjlist[k].data);
					ArcNode*p = g->adjlist[k].firstarc;;
					while (p != NULL) {
						printf("%d ", p->adjvex);
						p = p->nextarc;
					}
					printf("\n");
				}
				*/
	}
}


int path[MAXN];
int visit[100];
void DFS(graph g,int v, int to,int d) {//函数主体
	visit[v] = 1;//标记当前节点已经访问
	path[++d] = v;//存入路径数组
	if (v == to && d > 1) {//如当前节点是要寻找的重点
		for (int i = 0; i <= d; i++) {//输出路径
			printf("%d ", path[i]);
		}
		printf("\n");
	}
	ArcNode *p = g.adjlist[v].firstarc;//p指向当前节点第一个邻接节点
	while (p != NULL) {
		if (!visit[p->adjvex]) {//若当前节点未被访问
			DFS(g, p->adjvex, to,  d);//遍历邻接节点
		}
		p = p->nextarc;//下一个邻接节点
	}
	visit[v] = 0;//标记当前节点为未访问
}

int main() { 
	memset(path, 0, sizeof(path));
	memset(visit, 0, sizeof(visit));
	creatgraph(g);
	DFS(*g, 1, 6, -1);
}
//test data{
6 8
1 2
1 3
2 4
2 3
3 4
4 5
4 6
5 6
}