#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
const int MAXN = 100;

typedef struct ArcNode {
	int adjvex;
	ArcNode* nextarc;
};



typedef struct Vnode {
	int data;
	ArcNode* firstarc;
};

typedef struct Graph {
	Vnode adjlist[MAXN];
	int n, e;
}graph;



int* count(Graph g) {
	int *indegree = new int[g.n+1];//新建indegree记录数组
	memset(indegree, 0, sizeof(int)*(g.n + 1));//初始化为0
	for (int i = 1; i <= g.n; i++) {//遍历邻接表
		ArcNode*p = g.adjlist[i].firstarc;//边界点入度++
		while (p != NULL) {
			indegree[p->adjvex]++;
			p = p->nextarc;
		}
	}
	return indegree;//返回答案数组
}


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
	int *ans = count(*g);
	for (int i = 1; i <= g->n; i++) {
		printf("%d ", ans[i]);
	}
}

