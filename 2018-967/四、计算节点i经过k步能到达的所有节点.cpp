#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<algorithm>
const int n = 5;
using namespace std;
int a[n][n] = {
		0,1,1,0,0,
		1,0,1,1,0,
		1,1,0,1,0,
		0,1,1,0,1,
		0,0,0,1,0,
};
int visit[n];
int print[n];
void DFS(int v, int step, int k) {
	visit[v] = 1;//标记当前节点已访问
	if (step == k && !print[v]) {//当前节点距起点距离等于k且尚未输出过，输出
		printf("%d ", v);
		visit[v] = 0;//置为未访问
		print[v] = 1;//标记已输出过
		return;//返回
	}

	for (int i = 0; i < n; i++) {//遍历所有邻接节点
		if (a[v][i] == 1 && !visit[i]) {//深度搜索所有未访问过的邻接节点
			DFS(i, step + 1, k);
		}
	}
	visit[v] = 0; //  置为未访问
}

 

int main() {
	memset(visit, 0, sizeof(visit));//初始化访问标记数组
	memset(print, 0, sizeof(print));//初始化输出标记数组
	int n;
	while (scanf("%d", &n) != EOF) {
		memset(visit, 0, sizeof(visit));
		memset(print, 0, sizeof(print));
		for (int i = 1; i <= n; i++) {//遍历所有小于等于k的步数所能到达的点
			DFS(0, 0, i);//调用函数
		}
		printf("\n");//仅为美观
	}

}