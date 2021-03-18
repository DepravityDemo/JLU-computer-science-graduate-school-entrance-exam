#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>

int xs(int n,int k) {//计算二项式系数，k代表n个数中有k个2
	if (k == 0 && n == k)return 1;//C00情况
	if (k == 0)return 2 * xs(n - 1, k);//Cn0情况
	if (k == n)return 3* xs(n - 1, k - 1);//Cnn情况
	else return 2 * xs(n - 1, k) + 3 * xs(n - 1, k - 1);//Cnk情况使用公式Cnk=Cn-1 k-1+Cn-1 k;
}


int main() {
	int n,k;
	while (scanf("%d %d", &n,&k) != EOF) {
		printf("%d\n", xs(n,k));//计算二项式系数
	}
}