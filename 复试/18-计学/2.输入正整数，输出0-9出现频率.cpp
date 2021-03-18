#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
int main() {
	int num[10];//0-9数组
	memset(num, 0, sizeof(num)); //初始化出现次数为0
	int n;//储存读入数字
	while (scanf("%d", &n) != EOF) {//读入数字
		while (n != 0) {//对应出现的数字个数++
			num[n % 10]++;
			n = n / 10;
		}
		for (int i = 0; i < 10; i++) {//输出结果
			printf("%d:%d\n", i, num[i]);
		}
	}
}