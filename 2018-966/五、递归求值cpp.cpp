#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
int fact(int n) {//阶乘计算
	if (n == 0 or n == 1)return 1;
	else return n * fact(n - 1);
}



double fun(int n) {
	if (n == 0)return 0;//如果n=0返回0
	else return n*1.0 / (n + 1) / fact(n + 2) + fun(n - 1);//返回当前项加之前项
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {//读入数据
		printf("%lf",fun(n));//输出结果
	}
}