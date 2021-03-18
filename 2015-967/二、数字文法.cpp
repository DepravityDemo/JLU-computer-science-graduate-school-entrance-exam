#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
bool judge(char str[]) {
	for (int i = 0; str[i] != '\0'; i++) {//逐位判断是否为数字
		if (!(str[i] >= '0'&&str[i] <= '9'))return false;//如果有一位不是则返回false
	}
	return true;//全部都是返回true
}

int main() {
	char str[100];//储存字符串
	while (scanf("%s", str) != EOF) {
		if (judge(str))  printf("%s\n",str);//如果是是数字组成输出本身，否则输出错误
		else printf("错误\n");
	}
		
}