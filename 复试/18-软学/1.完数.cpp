#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

bool isfullnum(int n) {//函数主体
	int sum = 0;//定义约数和
	for (int i = 1; i < n; i++) {
		if (n%i == 0) {//能整除就是约数
			sum += i;//累加
		}
	}
	if (sum == n) {//如果真约数等于本身，则是完数
		return true;
	}
	else {
		return false;//否则不是
	}
}

int main() {
	for (int i = 1; i < 1000; i++) {//遍历1-1000所有数
		if (isfullnum(i)) {//判断是否是完数
			printf("%d ", i);
		}
	}
}