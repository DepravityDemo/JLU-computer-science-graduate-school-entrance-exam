#define _CRT_SECURE_NO_DEPRECATE //保证VS不检测scanf错误
#include<stdio.h>

int main() {
	char a[100];//储存二进制字符串的字符数组
	int sum=0;//存储十进制数
	scanf("%c", &a[0]);//读入第一个字符
	int len=0;//标记总长度
	while (a[len] != '*') {//循环读入所有非*字符
		len++;
		scanf("%c", &a[len]);
	}
	a[len] = '\0';//截断字符串
	for (int i = 0; a[i]!='\0'/* or i<len*/; i++) {
		sum = sum*2+(a[i] - '0');//二进制数转十进制数
	}
	printf("%d", sum);//输出答案

}

