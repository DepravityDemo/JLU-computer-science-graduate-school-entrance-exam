#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

void yh(int n) {
	int a[10][10];//储存杨辉三角
	memset(a, 0, sizeof(a));//初始化二维数组
	for (int i = 0; i < 10; i++) {//生成杨辉三角
		for (int j = 0; j <=i; j++) {
			if (j == 0 || i == j) {
				a[i][j] = 1;
			}
			else {
				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
			}
		}
		if (i == n - 1)break;//到达题目要求行跳出循环
	}
	for (int i = 0; i < n; i++) {//输出该行元素
		printf("%d ", a[n - 1][i]);
	}
	printf("\n");
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		yh(n);
	}
}