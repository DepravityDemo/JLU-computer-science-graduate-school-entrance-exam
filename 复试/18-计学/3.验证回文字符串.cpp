#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>


bool yz(char str[]) {
	int i = 0;//前指针
	int j = strlen(str) - 1;//后指针
	while (i < j) {//未重合时循环
		if (str[i] != str[j]) {//若前后不相等则返回flase
			return false;
		}
		i++;//前指针后移后指针前移
		j--;
	}
	return true;//指针重合返回true
}


int main() {
	char str[100];//定义数组储存字符串
	while (scanf("%s", str) != EOF) {
		if (yz(str))printf("1\n");//验证是否是回文字符串
		else {
			printf("0\n");
		}
	}
}