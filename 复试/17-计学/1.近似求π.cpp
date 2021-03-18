#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>

double pai() {
	int i = 1;//分母变量
	double tmp = 1;//每项值
	double ans=0;//答案
	while (fabs(tmp) > 1e-5) {//精度未达到，循环
		ans += tmp;//累加
		i++;//更新分母变量
		if (i % 2 != 0) {//奇数项为正，偶数项为负
			tmp = 1.0/ (2 * i - 1);
		}
		else {
			tmp = -1.0 / (2 * i - 1);
		}
		
	}
	return ans * 4;//因求π，要根据公式乘4
}


int main() {
	printf("%lf", pai());
}