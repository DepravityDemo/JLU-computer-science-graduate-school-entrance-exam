#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int n = 5;
int color[n];//本题以5节点为例进行解答
int c = 4;//颜色个数
int 	 a[5][5] = {
		0,1,1,1,1,
		1,0,1,1,0,
		1,1,0,1,1,
		1,1,1,0,1,
		1,0,1,1,0,
};
int check(int k) {
	for (int i = 0; i < k; i++) {//遍历k*k的邻接矩阵
		if (a[i][k] == 1 && color[i] == color[k]) {//a[i][k]==1说明有边，color[i]==color[k]说明颜色重合不符合要求
			return false;
		}
	}
	return true;//遍历到结尾还未发现冲突则返回true
}
int count = 0;
void graphcolor(int step) {
	if (step == n) {//所有节点都已赋值合法颜色，输出
		for (int i = 0; i < c; i++) {
			printf("%d ", color[i]);
		} 
		count++;//计数变量
		printf("\n");
		return;//回溯
	}
	else {
		for (int i = 1; i <= c; i++) {//遍历所有颜色选择
			color[step] = i;//标记当前节点颜色
			if (check(step) == 1) {//检查是否合法
				graphcolor(step + 1);//合法则递归对下一节点进行检查
			}
		}
	}
}

int main() {
	graphcolor(0);
	printf("%d", count);
	return 0;
}