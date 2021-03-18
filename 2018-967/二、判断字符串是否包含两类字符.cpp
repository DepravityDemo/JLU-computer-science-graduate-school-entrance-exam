#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

bool isright(char str[]) {
	int flagzm = 0;//小写字母标识
	int flagZM = 0;//大写字母标识
	int flagsz = 0;//数字标识
	int len = strlen(str);//计算字符串长度
	for (int i = 0; i < len; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			flagsz = 1;//若是数字更新数字标识
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			flagzm = 1;//若是小写字母更新小写字母标识
		}
		else if (str[i] >= 'A'&& str[i] <= 'Z') {
			flagZM = 1;//若是大写字母更新大写字母标识
		}
		if (flagzm + flagZM + flagsz > 1) {//若已经出现2个，返回true
			return true;

		}
	}
	return false;//到字符串末尾也为满足条件返回false
}


int main() {
	
	char str[100];
	while (scanf("%s", str) != EOF) {
		if (isright(str)) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
	
}