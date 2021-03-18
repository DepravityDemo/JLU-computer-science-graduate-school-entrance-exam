#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

void fj(int n) {
	int a[100];//储存各位数字
	int k = 0;
	while (n != 0) {
		if ((n % 10) % 2 != 0){//如果本位是奇数，则保留
		a[k++] = n % 10;
		}
		n = n / 10;//取下一位
	}
	for (int i = k-1;i>=0; i--) {//因从个位开始储存的，所以答案要倒序输出
		printf("%d", a[i]);
	}
	printf("\n");
}



int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		fj(n);
	}
}