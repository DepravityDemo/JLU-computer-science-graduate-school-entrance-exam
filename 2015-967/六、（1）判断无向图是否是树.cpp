#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
const int MAXN = 100;
typedef struct ArcNode{//边界点结构体
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
		/*输出c测试
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
int Enum, Vnum;//Enum记录边数， Vnum记录顶点数
int visit[MAXN];//标记是否已访问数组
void dfs(graph g, int v, int &Vnum, int&Enum, int visit[]) {//v表示当前节点，Vnum和Enum因要改变其值，故使用
	visit[v] = 1;//标记当前节点已访问
	Vnum++;//访问节点数+1；
	ArcNode *p = g.adjlist[v].firstarc;//p指向当前节点第一个邻接节点
	while (p != NULL) {
		Enum++;//p不为空说明存在一条边
		if (!visit[p->adjvex]) {//p的邻接节点若未被访问
			dfs(g, p->adjvex, Vnum, Enum, visit);//访问它
		}
		p = p->nextarc;//p指向下一邻接节点
	}
}



bool istree(graph g) {
	Enum = 0;
	Vnum = 0;
	memset(visit, 0, sizeof(visit));//visit置0
	dfs(g, 1, Vnum, Enum, visit);//深度优先搜索图
	if (Vnum == g.n && Enum == 2 * (g.n - 1))return true;//无向图树的特点，边数为2*（顶点数-1）符合则返回true不符合返回false
	else return false;

}


int main() {
	graph g;
	creatgraph(&g);
	if (istree(g))return 1;
	else return 0;
}

/*testdata
不是树
3 3
1 2
1 3
2 3
是树
4 3
1 2
1 3
1 4

*/