#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;



int main() {
	int a[20][10];//定义数组
	for (int i = 0; i < 20; i++) {//进行循环读入数据
		for (int j = 0; j < 10; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	double sum = 0;//定义双浮点数储存答案
	for (int i = 0; i < 20; i++) {//累加左右边
		sum += a[i][0] + a[i][9];
	}
	for (int j = 1; j < 9; j++) {//累加上下边，从1到9因为左右两遍在上边已经计算过一遍
		sum += a[0][j] + a[19][j];
	}
	sum = sum / 56;//求平均数
	printf("%lf", sum);//输出
}