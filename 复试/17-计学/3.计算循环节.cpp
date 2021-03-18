#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>

int pos;//pos为循环节起始


bool find(int Dec[], int Rem[], int con, int r, int q) {//判断当前con和r是否在Dec和Rem中出现过
	for (int i = 0; i < q; i++) {//未到结尾则遍历
		if (Dec[i] == con && Rem[i] == r) {//找到了
			pos = i;//定义循环节开始
			return true;//返回找到了
		}
	}
	return false;//到末尾还没找到，返回没找到
}




void cal(int a, int b) {
	int Dec[100];//储存各位商数组
	int Rem[100];//储存各位余数数组
	memset(Dec, 0, sizeof(Dec));//初始化为0
	memset(Rem, 0, sizeof(Rem));//初始化为0
	int con, r, end=-1, q=0;//con表示临时商，r表示临时余数，end为循环节结尾，q为Dec末尾指针
	int Int;//储存整数部分
	Int = a / b;//取整数部分
	if (a > b) {
		a = a % b;//化为真分数
	}
	con = a * 10 / b;//初始化第一组商
	r = (a * 10) % b;//初始化第一组余数
	while (!find(Dec, Rem, con, r, q)) {//数组中没找到则循环
		Dec[q] = con;//存入商数组
		Rem[q] = r;//存入余数数组
		q++;//结尾指针后移
		con = r * 10 / b;//计算下一组商
		r = (r * 10) % b;//计算下一组余数
	}
	printf("%d.", Int);//输出整数部分
	for (int i = 99; i >= 0; i--) {//计算循环节末尾
		if (Dec[i] != 0) {
			end = i;//记录循环节末尾
			break;
		}
	}
	if (end == -1) {//能够被整除
		printf("0");//补0
	}
	for (int i = 0; i < pos; i++) {//输出不循环部分
		printf("%d", Dec[i]);
	}
	for (int i = pos; i <= end; i++) {//输出循环部分
		if(i==pos)printf("(");//前括号
		printf("%d", Dec[i]);
		if(i==end)printf(")");//后括号
	}
	printf("\n");//换行
}

int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		cal(a, b);
	}
}