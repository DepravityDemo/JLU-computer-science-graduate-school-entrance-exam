#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

void add(int a[], int n) {
	int i = n - 1;
	while (a[i] == 1) {//所有连续的1，变成0，遇到的第一个0，变成1；
		a[i] = 0;
		i--;
	}
	if (i != -1) {//判断位数是否需要增加
		a[i] = 1;
	}
	else {
		for (int i = 1; i <= n; i++) {//数组内元素全为1，加一需增加一位
			a[i] = 0;
		}
		a[0] = 1;//进位首元素为1
		n++;//数组长度+1
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);//输出数组
	}
	printf("\n");
}




int main() {
	int a[5] = { 1,1,1,1 };
	add(a, 4);
}