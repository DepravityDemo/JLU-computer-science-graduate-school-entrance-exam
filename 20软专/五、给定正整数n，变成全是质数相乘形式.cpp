#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main() {
	int n;
	int flag;
	scanf("%d", &n); //读入数据
	flag = 1;
	int cot = 0;//记录因数个数
	printf("%d=", n);//格式输出
	for (int i = 2; n!=1; i++) {
		while (n%i == 0) {//若能整除，使用while适应n可以多次被i整除情况
			if (flag) {//flag控制*号输出
				printf("%d", i);//输出质因数
				flag = 0;
			}
			else {
				printf("*%d", i);
			}
			n = n / i;//n更新
			cot++;//记录因数个数
		}
	}
	return cot;//返回因数个数
}