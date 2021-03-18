#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
int pos = 0;
bool find(int Dec[], int Rem[], int con, int r, int q) {//查找有误出现重复余数和商相同的一对
	for (int i = 0; i < q; i++) {//遍历DEC和REM数组
		if (Dec[i] == con && Rem[i] == r) {//两者都相等则
			pos = i;//定位循环节开头
			return true;//返回已找到
		}
	}
	return false;//到表尾也未找到，则返回未找到
}

void cal(int a, int b) {
	int Dec[100];//储存商
	int Rem[100];//储存余数
	memset(Dec, 0, sizeof(Dec));
	memset(Rem, 0, sizeof(Rem));
	int con, r, q=0;//con临时商，r临时余数,q为DecRem结尾指针
	int Int;//储存整数部分
	int end = -1;
	Int = a / b;//记录整数部分
	if (a >=b) {
		a = a % b;//化为真分数
	}
	con = a * 10 / b;//计算第一组商
	r = (a * 10) % b;//计算第一组余数
	while (!find(Dec, Rem, con, r, q)) {//在表中未出现循环节
		Dec[q] = con;//如果表中未出现过，则存储
		Rem[q] = r;//如果表中未出现过，则存储
		q++;//数组尾变量
		con = r * 10 / b;//计算下一组商
		r = (r * 10) % b;
	}
	printf("%d.", Int);//输出整数部分
	for (int i = 0; i < pos; i++) {//输出不循环小数部分
		printf("%d", Dec[i]);
	}
	for (int i = 99; i >= 0; i--) {//寻找循环节末尾
		if (Dec[i] != 0) {
			end = i;
			break;
		}
	}
	if (end == -1) {//若没有小数部分
		printf("0");//补0
	}
	for (int i = pos; i <=end; i++) {//输出循环小数部分
		if (i == pos) {//开头输出左括号
			printf("(");
		}
		printf("%d", Dec[i]);
		if (i == end) {//结尾输出右括号
			printf(")");
		}
	}

}



int main() {
	int n, d;
	while (scanf("%d %d", &n, &d) != EOF) {

		cal(n, d);
	}
}