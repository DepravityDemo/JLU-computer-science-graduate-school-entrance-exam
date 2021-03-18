#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;
bool isprime(int n) {//判断是否是素数
	if (n < 2) {
		return false;
	}
	for (int i = 2; i < n / 2; i++) {
		if (n%i == 0)return false;
	}
	return true;
}
void fj(int n) {//分解过程函数体
	if (n % 2 != 0) {
		printf("It is not even number\n");//不是偶数退出
		return;
	}
	for (int i = 2; i <=n; i++) {
		if (isprime(i) && isprime(n - i)) {//i与n-i同为质数时输出。因只要求输出一组，所以加了break，想输出全部可能可以去掉break
			printf("%d=%d+%d\n", n,i,n - i);
			break;
		}
	}
}


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		fj(n);
	}
}