#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int a[10];//储存每位数字
	int k = 0;//储存数字位数
	while (scanf("%d", &n) != EOF) {//读入正整数
		k = 0;
		while (n != 0) {
			a[k++] = n % 10;
			n = n / 10;
		}
		sort(a, a + k, greater<int>());//对所有数字降序排序
		for (int i = 0; i < k; i++) {//输出答案
			printf("%d", a[i]);
		}
		printf("\n");
	}
	
}