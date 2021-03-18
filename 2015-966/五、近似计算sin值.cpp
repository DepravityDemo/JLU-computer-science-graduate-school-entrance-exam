#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

double sin(double x) {
	double sum = 0;//初始化sum储存答案
	double tmp = x;//每项值
	int n = 1;//变化改变变量
	while (fabs(tmp) > 1e-5) {
		sum += tmp;//累加
		tmp = -tmp * x*x / (n + 1) / (n + 2);//更新每项值
		n+=2;//更新n
	}
	return sum;//返回答案
}
int main() {
	double x;
	while (scanf("%lf", &x) != EOF) {
		printf("%lf",sin(x));//调用函数
	}
}