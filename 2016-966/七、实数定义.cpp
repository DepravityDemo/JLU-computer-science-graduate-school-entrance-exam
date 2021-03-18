#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

bool judge(char str[], double x) {
	double ans = 0.0;
	int len = strlen(str);//获取字符串长度
	int pos=0;//定位小数点
	for (int i = 0; i < len; i++) {
		if (!((str[i] >= '0'&&str[i] <= '9') || str[i] == '.')) {//如果非数字和小数点则直接返回false
			return false;
		}
		else if (str[i] >= '0'&&str[i] <= '9') {//若是数字，则记录先不考虑小数点
			ans = ans * 10 + str[i]-'0';
		}
		if (str[i] == '.') {//定位小数点
			pos = i;
		}
	}
	ans = ans / pow(10, len-pos-1);//计算小数点需要放在哪
	if (ans > x)return true;//如果ans比x大，返回true
	else return false;//否则返回false
}


int main() {
	char str[100];
	double x;
	while (scanf("%s", str) != EOF) {
		scanf("%lf", &x);
		printf("%d\n", judge(str, x));
	}
}

