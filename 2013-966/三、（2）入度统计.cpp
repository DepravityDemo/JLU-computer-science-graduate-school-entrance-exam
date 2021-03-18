#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<iostream>
using namespace std;
const int MAXN = 100;
typedef struct ArcNode {
	int adjvex;
	ArcNode *nextarc;
};

typedef struct Vnode {
	int data;
	ArcNode* firstarc;
};

typedef struct Graph {
	Vnode adjlist[MAXN];
	int n, e;
};
int indegree[MAXN];

void count(Graph g) {//函数主体
	for (int i = 1; i <= g.n; i++) {//遍历所有节点
		ArcNode* p = g.adjlist[i].firstarc;//p指向当前节点第一个邻接节点
		while (p != NULL) {//p不为空继续
			indegree[p->adjvex]++;//p指向节点的入度++
			p = p->nextarc;//p指向下一个节点
		}
	}
}
void creatgraph(Graph *g) {//创建图过程考试不要求
	int i, j;
	printf("n,e = ");
	scanf("%d %d", &g->n, &g->e);//读入节点数边数
	printf("Please input jd informatin: ");//读入各边
	for (int k = 1; k <= g->n; k++) {//初始化顶点节点
		g->adjlist[k].data = k;
		g->adjlist[k].firstarc = NULL;
	}
	printf("Please input the from and to: ");//读入边并构建邻接表
	for (int k = 1; k <= g->e; k++) {
		ArcNode * p;
		scanf("%d %d", &i, &j);
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->nextarc = g->adjlist[i].firstarc;;
		g->adjlist[i].firstarc = p;

		//p = (ArcNode*)malloc(sizeof(ArcNode));//如果是有向图这部分代码要省略！
		//p->adjvex = i;
		//p->nextarc = g->adjlist[j].firstarc;
		//g->adjlist[j].firstarc = p;
		/*输出测试
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
int main() {
	memset(indegree, 0, sizeof(indegree));
	Graph *g = (Graph*)malloc(sizeof(Graph));
	creatgraph(g);
	count(*g);
	for (int i = 1; i <= g->n; i++) {
		printf("%d:%d\n",i, indegree[i]);
	}

}