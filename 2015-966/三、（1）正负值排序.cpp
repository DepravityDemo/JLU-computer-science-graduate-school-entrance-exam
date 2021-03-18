#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>.
#include<string.h>



void sort(int a[], int n) {//函数主体
	int i = 0;//左指针
	int j = n - 1;//右指针
	while (i <j) {
		while (a[i] < 0)i++;//寻找第一个负数
		while (a[j] >= 0)j--;//倒序寻找第一个非负
		if (i < j) {//交换
			int tmp = a[i];//临时变量
			a[i] = a[j];
			a[j] = tmp;
		}
	}
}

int main() {
	int a[8] = { 7,4,-1,-5,-6,3,-4,8 };
	sort(a, 8);
	for (int i = 0; i < 8; i++) {
		printf("%d ", a[i]);
	}
}