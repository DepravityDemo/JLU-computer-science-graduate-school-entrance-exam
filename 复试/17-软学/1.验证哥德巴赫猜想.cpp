#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
bool isprime(int n) {//判断当前数字是否是数字
	if (n < 2)return false;
	for (int i = 2; i <= n / 2; i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {//读入数据
		if (n < 6 || n % 2 != 0) {//输入不规范输出输入出错
			printf("input error!\n");
		}
		else {
			for (int i = 2; i < n; i++) {//遍历
				if (isprime(i) && isprime(n - i)) {//i与n-i同为素数输出
					printf("%d=%d+%d\n", n, i, n - i);
					break;//若要输出全部可能可去掉break，否则输出一种
				}
			}
		}
	}
}