#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>

int js(int n) {
	int ans = 0;
	while (n) {//因5与偶数相乘会出线0，易知偶数个数必然多余5倍数个数，固只需计算5的倍数的个数即可计算出结尾0的个数
		ans += n/ 5;//累加0个数
		n /= 5;//相当于第一遍n/5第二遍n/25第三遍n/125
	}
	return ans;//返回答案
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {//读入数据
		printf("%d\n", js(n));//输出答案
	}
}