#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
const int MAXN = 100;
//算法设计思想，利用Dijkstra算法求支撑树，即在求最短路径时，将最短路径边加入生成树T
typedef struct ArcNode {//边节点储存结构
	int adjvex;
	ArcNode* nextarc;
};

typedef struct Vnode {//顶点节点储存结构
	int data;
	ArcNode* firstarc;
};

typedef struct graph {//邻接表图/支撑树储存结构
	Vnode adjlist[MAXN];
	int n, e;
};

typedef struct Edge {//边储存结构
	int from;
	int to;
	int weight;
};

int dis[MAXN];//储存最短路径长度