#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
const int MAXN = 100;
typedef struct ArcNode {//边界点结构体
	int adjvex;
	ArcNode *nextarc;
};

typedef struct Vnode {//顶点结构体
	int data;
	ArcNode *firstarc;
};

typedef struct Graph {//图结构体
	Vnode adjlist[MAXN];
	int n, e;
}graph;
graph *g = (graph*)malloc(sizeof(graph));
int t;
void creatgraph(graph *g) {//创建图过程考试不要求
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

		p = (ArcNode*)malloc(sizeof(ArcNode));//如果是有向图这部分代码要省略！
		p->adjvex = i;
		p->nextarc = g->adjlist[j].firstarc;
		g->adjlist[j].firstarc = p;
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
	creatgraph(g);
}

