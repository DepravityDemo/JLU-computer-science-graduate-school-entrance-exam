#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

void fj(int n) {
	int i;
	int flag = 1;//输出辅助标记
	if (n == 1)printf("0\n");//n=1时输出0
	else {
		printf("%d=", n);//输出原数
		for (int i = 2; i <= n; i++) {
			while (n%i == 0) {//如果整除说明是因子，可能多次整除，故使用while
				if (flag) {//第一个数字不输出乘号
					printf("%d", i);
					flag = 0;
				}
				else {
					printf("*%d", i);//后续输出乘号
				}
				n = n / i;//更新n
			}
		}
		
	}
}


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		fj(n);
	}
}