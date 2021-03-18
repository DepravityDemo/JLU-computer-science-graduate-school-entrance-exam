#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100;

typedef struct ArcNode {
	int adjvex;
	ArcNode *nextarc;
};



typedef struct Vnode {
	int data;
	ArcNode * firstarc;
};
typedef struct Graph {
	Vnode adjlist[MAXN];
	int n;
	int e;
}graph;


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
int topo[100];//储存结果
int visit[100];//标记是否访问过
int t;
bool dfs(int v) {
	visit[v] = 1;//标记当前节点已访问
	ArcNode *p = g->adjlist[v].firstarc;//p指向邻接节点
	while (p != NULL) {
		if (!visit[p->adjvex]) {//若当前节点邻接节点未被访问
			dfs(p->adjvex);//访问邻接节点
		}
		p = p->nextarc;//访问下一个邻接节点
	}
	topo[t--] = v;//最后被访问的节点最后输出（DFS）最后一层
	return true;
}



int main() {
	creatgraph(g);
	memset(visit, 0, sizeof(visit));
	t = g->n;
	for (int i = 1; i <= g->n; i++) {//
		if (!visit[i]) {
			dfs(i);//若节点未访问，拓扑排序
		}
	}

	for (int i = 1; i <= g->n; i++) {
		printf("%d", topo[i]);//输出拓扑排序序列
	}
}

//test data
/* 5 5 
1 2 
1 3 
2 4 
3 4 
4 5*/