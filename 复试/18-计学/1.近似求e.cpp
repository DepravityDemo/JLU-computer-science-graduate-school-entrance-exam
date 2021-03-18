#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {//函数主体

	double ans = 1;//初始化答案为1
	int n = 1;//初始化分母变量
	double tmp = 1;//初始化每项
	while (tmp > 1e-5) {//当前项没达到精度1e-5则循环
		ans += tmp;//累加
		tmp = tmp*1.0 / ++n;//阶乘只需在前一项基础再除个n即可
	}
	printf("%lf", ans);//输出答案

}