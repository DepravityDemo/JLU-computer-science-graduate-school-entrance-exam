#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

bool isprime(int n) {//判断是否是素数
	if (n < 2)return false;
	else {
		for (int i = 2; i <= n / 2; i++) {
			if (n%i == 0)return false;
		}
	}
	return true;
}


void sort(int a[], int n) {//函数主体
	int i = 0;//前指针
	int j = n - 1;//后指针
	while (i < j) {//i指针未重合时循环
		while (isprime(a[i]))i++;//寻找第一个素数
		while (!isprime(a[j]))j--;//倒叙寻找第一个非素数
		if (i < j) {//如果i<j则调换
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
}



int main() {
	int a[10] = { 7,4,2,8,5,1,6,3,9,0 };//测试数组
	sort(a,10);
	for (int i = 0; i < 10; i++) {//输出结果
		printf("%d ", a[i]);
	}
	printf("\n");
}