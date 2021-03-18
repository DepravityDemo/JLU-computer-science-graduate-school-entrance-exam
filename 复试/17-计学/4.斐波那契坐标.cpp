#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
int fb(int n) {//计算斐波那契数列值
	if (n == 0 or n == 1) {
		return 1;
	}
	else{
		return fb(n - 1) + fb(n - 2);
	}
}


void  fun(int n) {
	printf("(0,0) ");//从0,0点开始第一个
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			printf("(%d,0) ", fb(i));//奇偶不同输出不同格式菲波那切数列值
		}
		else {
			printf("(0,%d) ", fb(i));
		}
	}
	printf("\n");
}


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		fun(n);
	}
}