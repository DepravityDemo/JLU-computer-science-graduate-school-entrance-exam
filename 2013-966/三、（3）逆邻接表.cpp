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

void convert(Graph *a,Graph *b) {//函数主体
	for (int i = 1; i <= a->n; i++) {//遍历所有节点
		ArcNode* p = a->adjlist[i].firstarc;//p指向当前节点第一个邻接节点
		while (p != NULL) {//p不为空继续
			ArcNode *tmp = (ArcNode*)malloc(sizeof(ArcNode));//新建节点
			tmp->adjvex = a->adjlist[i].data;//新节点数据域为当前表头节点值（从这能到tmp）
			tmp->nextarc = b->adjlist[p->adjvex].firstarc;//头插法插入目标节点的firstarc
			b->adjlist[p->adjvex].firstarc = tmp;
			p = p->nextarc;//p指向下一个节点//遍历下一个节点
		}
	}
	int tmp = 0;
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
	Graph *a = (Graph*)malloc(sizeof(Graph));
	creatgraph(a);
	Graph *b = (Graph*)malloc(sizeof(Graph));
	b->e = a->e; b->n = a->n;
	for (int k = 1; k <= b->n; k++) {//初始化新链表
		b->adjlist[k].data = k;
		b->adjlist[k].firstarc = NULL;
	}
	convert(a,b);

	for (int i = 1; i <= a->n; i++) {
		printf("%d:%d\n",i, indegree[i]);
	}

}

//test data

/*
5 5
1 2
1 3
2 4
3 4
4 5
*/