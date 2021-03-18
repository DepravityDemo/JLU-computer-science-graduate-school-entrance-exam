#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 100;
int visit[MAXN];


typedef struct ArcNode {
	int adjvex;
	ArcNode * nextarc;
};

typedef struct Vnode {
	int  data;
	ArcNode *firstarc;
};

typedef struct graph {
	Vnode adjlist[MAXN];
	int n, e;
};

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
int flag = 0;
void dfs(graph g,int v, int visit[]) {
	if (flag) {//如果已经有环，直接返回
		return;
	}
	visit[v] = 0;//标记当前节点正在访问
	ArcNode*p = g.adjlist[v].firstarc;//p为当前节点邻接节点
	while (p != NULL) {
		if (visit[p->adjvex] == 0) {//如果与x相连节点状态也为0，说明有环
			flag = 1; return;//flag置1，返回
		}
		if (visit[p->adjvex]==-1) {//如果当前节点还未访问
			dfs(g, p->adjvex, visit);//继续搜索p的邻接节点
		}
		p = p->nextarc;//p指向下一个邻接节点
	}
	visit[v] = 1;//对v访问结束
}



int main() {
	memset(visit, -1, sizeof(visit));//初始化标记数组。-1表示未访问，0表示正在访问，1表示已访问
	graph *g = (graph*)malloc(sizeof(graph));
	creatgraph(g);
	dfs(*g, 1, visit);
	if (flag) { printf("true\n"); }
	else {
		printf("false\n");
	}
}