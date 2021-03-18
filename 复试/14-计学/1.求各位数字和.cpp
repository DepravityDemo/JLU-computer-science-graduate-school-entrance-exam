#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
using namespace std;

int sum(int n) {
	int ans = 0;//定义答案
	while (n != 0) {
		ans += n % 10;//逐位取数并求和
		n = n / 10;
	}
	return ans;//返回答案
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {//读入数据
		printf("%d",sum(n));//输出答案
	}
}