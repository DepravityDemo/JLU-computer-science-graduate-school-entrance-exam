#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

void Sin(double x) {
	double sum = 0.0;//sin值
	double tmp = x;//单项
	int n = 1;
	while (fabs(tmp) > 1e-8){//判断是否达到精度
		sum += tmp;//累加
		tmp = -tmp*x*x/ (n + 1) / (n + 2);//单项变下一项
		n+=2;
	}
	printf("%lf\n", sum);
}





int main() {
	double x;
	while (scanf("%lf", &x) != EOF) {//读入X值
		Sin(x);
	}
}