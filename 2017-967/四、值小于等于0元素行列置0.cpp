#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
using namespace std;

int main() {
	const int m = 5;
	const int n = 5;
	int a[m][m] = {
		11,12,13,14,15,
		21,0,23,24,25,
		31,32,33,34,35,
		41,42,43,-1,45,
		51,52,53,54,55
	};
	int col[n];//标记当前列是否被清零1为已清零
	int row[m];//标记当前行是否被清零1为已清零
	memset(col, 0, sizeof(col));
	memset(row, 0, sizeof(row));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] <=0) {
				row[i] = 1;//若当前元素小于等于0，标记当前行列为清零状态
				col[j] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (row[i] == 1) {//若当前行被清零，执行清零操作
			for (int j = 0; j < n; j++) {
				a[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (col[i] == 1) {//若当前列被清零，执行清零操作
			for (int j = 0; j < n; j++) {
				a[j][i] = 0;
			}
		}
	}
	for (int i = 0; i < m; i++) {//输出运算后数组
		for (int j = 0; j < n; j++) {
			printf("%2d  ", a[i][j]);
			}
		printf("\n");
	}
}
