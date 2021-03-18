#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

bool fun(int a[], int n) {
	int sum = 0;//记录前i-1项总和
	for (int i = 0; i < n; i++) {
		if (a[i] == sum)return 1;//比较前i-1项和当前项，相等则return 1
		sum += a[i];//累加当前项
	}
	return 0;
}

int main() {
	const int n=8;
	int a[n] = { 1,2,4,8,15,20,38,43 };//测试数据
	printf("%d\n",fun(a, 8));

}

