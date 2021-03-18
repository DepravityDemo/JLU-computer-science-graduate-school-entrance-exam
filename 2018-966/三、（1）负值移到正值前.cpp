#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>


int main() {
	int a[10] = { 7,4,-3,-1,5,-6,8,2 };
	int i = 0, j = 9;//初始化前后置镇
	while (i < j) {//循环
		while (a[i] < 0)i++;//寻找第一个正值
		while (a[j] >= 0)j--;//从后往前找第一个负值
		if (i < j) {//交换值
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	for (int i = 0; i < 10; i++) {//输出值
		printf("%d ", a[i]);
	}
}