#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

int main() {
	int a[100];//被乘数
	int b[100];//乘数
	int c[100];//结果
	int m, n;
	int l1 = 0, l2 = 0;

	while (scanf("%d %d", &m, &n) != EOF) {//输入乘数被乘数
		memset(a, 0, sizeof(a));//初始化各数组为0
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		while (m != 0) {
			a[l1++] = m % 10;//分离各位
			m = m / 10;
		}
		while (n != 0) {
			b[l2++] = n % 10;//分离各位
			n = n / 10;
		}
		for (int i = 0; i <l1; i++) {//逐位相乘
			for (int j = 0; j < l2; j++) {
				c[i + j] += a[i] * b[j];
			}
		}
		for (int i = 0; i < l1+l2; i++) {//对超过10的位进行进位
			if (c[i] >= 10) {
				c[i + 1] += c[i] / 10;//进位
				c[i] = c[i] % 10;//进位后剩余
			}
		}
		int k = l1 + l2;//两数相乘最大不超过两数位数和
		while (c[k] == 0) { k--; }//去除多余0位
		while (k!=-1) {//输出结果
			printf("%d",c[k--]);
		}
	}
}