#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stack>


const int m = 5;
const int n = 5;

int main() {//本题即对数组进行升序排序
	int a[m][n] = {
		76,47,29,77,2,79,25,61,65,91,87,28,46,41,71,0,90,77,21,53,42,15,87,8,92
	};
	for (int i = 0; i < m*n - 1; i++) {//二维数组是行优先一维连续储存，固当做一维数组进行冒泡排序
		for (int j = i + 1; j < m*n; j++) {//冒泡排序过程
			if (a[0][i] > a[0][j]) {
				int tmp = a[0][i];
				a[0][i] = a[0][j];
				a[0][j] = tmp;
			}
		}
	}
	for (int i = 0; i < m; i++) {//输出排序后数组
		for (int j = 0; j < n; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n"); 
	}
}

