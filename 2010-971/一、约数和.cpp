#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
using namespace std;

void ysh(int n) {
	int flag = 1;//首个数字前无加号
	int sum = 0;//记录约数和
	for (int i = 1; i <=n; i++) {
		if (n%i == 0) {
			sum += i;//约数和累加
			if (flag == 1) {//输出约数
				printf("%d", i);
				flag = 0;
			}
			else {
				printf("+%d", i);
			}
		}
	}
	printf("=%d\n",sum);//输出约数和
}



int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		ysh(n);
	}
}