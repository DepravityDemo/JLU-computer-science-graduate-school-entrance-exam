#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>

double f(double x) {
	return x * x*x - x * x - 1;
}

int main() {
	double a, b, mid;//定义左右界限，中值
	a = 0; b = 3;//初始化左右界限
	mid = (a + b / 2);//初始化中值
	while (fabs(f(mid)) > 1e-4) {//对比中值的函数值是否达到界限
		if (f(mid)*f(a) > 0) {//若与左界限同号，左界限更新为mid
			a = mid;
		}
		else {
			b = mid;//若与右界限同号，右界限更新为mid
		}
		mid = (a + b) / 2;//重新计算中值
	}
	printf("%lf\n", mid);//输出答案
}