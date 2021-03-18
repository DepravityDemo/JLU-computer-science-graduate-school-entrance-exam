#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

using namespace std;

int gys(int m, int n) {//求m,n最大公约数
	if (m%n == 0)return n;
	else return gys(n, m%n);
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);//读入分子分母
	printf("%d/%d", m / gys(m, n), n / gys(m, n));//输出最简分数
}