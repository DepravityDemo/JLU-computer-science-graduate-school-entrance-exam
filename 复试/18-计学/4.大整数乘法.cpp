#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;




int main() {
	char a[100];
	char b[100];
	scanf("%s %s", a, b);
	int l1 = strlen(a);
	int l2 = strlen(b);
	reverse(a, a + l1);//逆转字符串，将个位放最前
	reverse(b, b + l2);//逆转字符串，将个位放最前
	int *ans = new int[l1+l2];//两数乘积不可能超过两数位数和
	memset(ans, 0, sizeof(int)*(l1 + l2));//初始化为0
	for (int i = 0; i < l1; i++) {//逐位相乘
		for (int j = 0; j < l2; j++) {
			ans[i + j] += (a[i]-'0') * (b[j]-'0');
		}
	}
	for (int i = 0; i < l1 + l2; i++) {//对超过10的数字整理进位
		if (ans[i] > 10) {
			ans[i + 1] += ans[i] / 10;//进位
			ans[i] = ans[i] % 10;//取余保存在当前位置
		}
	}
	int k;
	for (int i = l1 + l2-1; i >= 0; i--) {//删除最前面0元素
		if (ans[i] != 0) {
			k = i;//记录首位位置
			break;
		}
	}
	for (int i =k; i >=0; i--) {//输出结果
		printf("%d", ans[i]);
	}
}