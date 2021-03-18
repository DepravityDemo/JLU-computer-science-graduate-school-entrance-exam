#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
const int INF = 999999;
struct Edge {//定义边节点
	int to;//目标节点
	int length;//权重
	Edge(int t, int l) :to(t), length(l) {}; //重载海曙
};
const int MAXN = 200;//定义最大值
struct Point {//定义节点
	int number;//定义序号
	int distance;//定义距离
	Point(int n, int d) :number(n), distance(d) {};//重载小于号
	bool operator <(const Point&p)const {
		return distance > p.distance;//数值小的在前边
	}
};
int dis[MAXN];
vector<Edge>graph[MAXN];
void Dijkstr(int s) {
	priority_queue<Point>myqueue;//定义优先队列（这里使用优先队列保证最小dist边在队首）
	dis[s] = 0;//初始化原点距离为0
	myqueue.push(Point(s, dis[s]));//原点入队
	while (!myqueue.empty()) {//队飞空循环
		int u = myqueue.top().number;//最近点
		myqueue.pop();
		for (int i = 0; i < graph[u].size(); i++) {//遍历该节点为起点的边
			int v = graph[u][i].to;//v指向目的节点
			int d = graph[u][i].length;//记录当前边权重
			if (dis[v] > dis[u] + d) {//如果当前点dis+d小于目标节点dis
				dis[v] = dis[u] + d;//更新目标节点最小dis
				myqueue.push(Point(v, dis[v]));//目标节点入队
			}
		}
	}
	return;
}


int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {//读入顶点数，边数
		memset(graph, 0, sizeof(graph));//初始化图
		fill(dis, dis + n, INF);//填充距离为dis
		while (m--) {//循环读入边
			int from, to, length;//定义源头，去向，权重
			scanf("%d %d %d",&from,&to,&length);//读入边
			graph[from].push_back(Edge(to, length));//将边储存入数组
			graph[to].push_back(Edge(from, length));
		}
		Dijkstr(0);//使用Dijkstr算法求最短路径
		int max = 0;
		for (int i = 0; i < n; i++) {//保存最短路径最大值
			if (dis[i] != INF && dis[i] > max) {
				max = dis[i];
			}
		}
		printf("%d", max);//输出T直径
	}
}