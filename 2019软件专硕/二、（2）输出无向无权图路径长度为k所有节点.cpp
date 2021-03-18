#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

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
int visit[MAXN];
typedef struct Point {//节点定义
	int vex;
	int num;
	Point(int v, int n):vex(v), num(n) {};
};
void BFS(int v,  int k) {//无权图使用BFS来搜寻路径长度为k节点//函数主体
	queue <Point>q;//定义队列
	q.push(Point(v,0));//入队
	visit[v] = 1;
	while (!q.empty()) {//队非空循环
		Point cur = q.front();//读取队头节点
		q.pop();//出队
		if (cur.num == k) {//判断是否符合条件
			printf("%d ", cur.vex);//输出符合条件答案
		}

		ArcNode *tmp = g->adjlist[cur.vex].firstarc;//tmp指向第一个边界点
		while (tmp != NULL) {
			if (!visit[tmp->adjvex]) {//如果该节点未被访问
				q.push(Point(tmp->adjvex, cur.num + 1));//节点入队
				visit[tmp->adjvex]=true;//标记节点已访问
			}
			tmp = tmp->nextarc;//遍历下一节点
		}
		
	}
}




int main() {
	creatgraph(g);//构建图
	memset(visit, 0, g->n);//初始化节点标记数组
	BFS(1,  2);//调用BFS
}

