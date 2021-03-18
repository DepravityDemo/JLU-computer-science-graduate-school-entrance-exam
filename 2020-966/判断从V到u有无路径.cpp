#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
const int MAXN = 100;
typedef struct ArcNode {
	int adjvex;
	ArcNode *nextarc;
};

typedef struct Vnode{
	int data;
	ArcNode *firstarc;
};
typedef struct Graph {
	Vnode adjlist[MAXN];
	int n; int e;
}*graph;
graph g = (graph)malloc(sizeof(Graph));

void creatgraph(graph g) {//创建图过程考试不要求
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

bool find(int v, int u) {//v为起点，u为终点，邻接表形式存储
	ArcNode *p = g->adjlist[v].firstarc;//p指向第一个邻接节点
	while (p != NULL) {//遍历邻接链表
		if (p->adjvex == u) {//找到目标节点说明有边
			return true;//返回true
		}
		p = p->nextarc;//p指向下一个邻接节点
	}
	return false;//到表尾还未找到，返回false
}

int main() {
	
	int v, u;
	creatgraph(g);//创建链表
	while (scanf("%d %d", &v, &u) != EOF) {//读入起点终点
		printf("%d",find(v, u));//判断有无边
	}
	

}