#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int main() {
	int n;
	int a[4];//储存各位数字
	int k = 3;//最后一位开始储存保持原序
	while (scanf("%d", &n) != EOF) {
		while (n != 0) {//分离各位数字在a[4]中
			a[k--] = n % 10;
			n = n / 10;
		}
		for (int i = 0; i < 4; i++) {//加密操作
			a[i] = (a[i] + 5) % 10;
		}
		for (int i = 3; i >= 0; i--) {//交换一四，二三位相当于倒序，所以直接逆序输出即为答案
			printf("%d", a[i]);
		}
		printf("\n");
	}
}