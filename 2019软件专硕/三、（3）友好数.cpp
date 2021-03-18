#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int ysh(int n) {//计算约数和
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n%i == 0) {//能整除
			sum += i;
		}
	}
	return sum;//返回约数和
}
int main() {
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {//读入m，n
		if (ysh(m)==n && m== ysh(n)) {//符合条件
			printf("YES\n");
		}
		else {//不符合条件
			printf("NO\n");
		}
	}
}