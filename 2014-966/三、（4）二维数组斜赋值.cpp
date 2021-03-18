#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>.
#include<string.h>
int main() {
	int a[10][10];//新建数组
	memset(a, 0, sizeof(a));//初始化数组
	int n = 1;//赋值变量
	int i, j;//行列指针
	for (int k = 0; k < 10; k++) {//k控制循环次数
		j = 0; i = k;//从每行第一个数字开始赋值
		while (i >= 0) {
			a[i--][j++] = n++;//斜上方赋值，i为0时停止
		}
	}
	for (int k = 1; k <10; k++) {////k控制循环次数
		i = 9; j = k;//最后一行第二列开始赋值
		while (j<10) {//j=9时到达边界终止
			a[i--][j++] = n++;//斜上方赋值
		}
	}
	for (int i = 0; i < 10; i++) {//输出答案
		for (int j = 0; j < 10; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
}