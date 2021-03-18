#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 100;

typedef struct ArcNode {
	int adjvex;
	ArcNode * nextarc;
};

typedef struct Vnode {
	int  data;
	ArcNode *firstarc;
	int dist;
};

typedef struct Graph {
	Vnode adjlist[MAXN];
	int n, e;
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

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->nextarc = g->adjlist[j].firstarc;
		g->adjlist[j].firstarc = p;
	}
	/*
			for (int k = 1; k <=g->n; k++) {
				printf("%d  ", g->adjlist[k].data);
				ArcNode*p = g->adjlist[k].fistarc;
				while (p != NULL) {
					printf("%d ", p->adjvex);
					p = p->nextarc;
				}
				printf("\n");
			}
			*/
}
int visit[MAXN];
void BFS(int from, int k) {
	for (int i = 0; i < g->n; i++) {
		g->adjlist[i].dist = 0;
	}//初始化所有节点dist为0；
	queue<Vnode>q;//建立队列用于BFS
	visit[from] = 1;//标记起点已访问
	q.push(g->adjlist[from]);//当前节点入队
	while (!q.empty()) {//如果队列不为空
		Vnode cur = q.front();//读取队头元素
		q.pop();//队头元素出队
		ArcNode *p = cur.firstarc;//p指向当前节点第一个边节点
		while (p != NULL) {
			if (visit[p->adjvex] == 0) {//如果当前边节点未被访问
				visit[p->adjvex] = 1;//访问当前节点
				g->adjlist[p->adjvex].dist=cur.dist+1;//当前节点等于队头节点距离+1
				q.push(g->adjlist[p->adjvex]);//当前节点入队
				if (g->adjlist[p->adjvex].dist == k) {//若当前节点距离等于k则输出
					printf("%d ", p->adjvex);
				}
			}
			p = p->nextarc;//p指向下一个邻接节点
		}
	}
}



int main() {
	creatgraph(g);
	memset(visit, 0, sizeof(visit));
	int from, k;
	while (scanf("%d %d", &from, &k) != EOF) {//读入起点与步数
		memset(visit, 0, sizeof(visit));
		BFS(from, k);//广度优先遍历走最短距离
	}
	
}