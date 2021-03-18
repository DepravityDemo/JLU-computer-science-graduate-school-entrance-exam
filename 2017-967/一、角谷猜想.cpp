#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int main() {
	int n;
	int cot;//计数器
	while (scanf("%d", &n) != EOF) {//读入数字
		cot = 0;//计数器归0
		while (n != 1) {//n不等于0时循环
			cot++;//步数+1
			if (n % 2 == 0) {//偶数处理
				n = n / 2;
			}
			else {//奇数处理
				n = 3 * n + 1;
			}
		}
		printf("%d\n", cot);//输出答案
	}
}