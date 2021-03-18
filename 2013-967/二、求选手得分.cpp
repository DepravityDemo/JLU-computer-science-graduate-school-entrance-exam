#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

int main() {
	int a[10];
	int max = 0;//初始化最小值
	int min = 999;//初始化最大值
	double sum = 0;//初始化总分
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
		sum += a[i];//记录总分
		if (max < a[i])max = a[i];//记录最大最小值
		if (min > a[i])min = a[i];
	}
	printf("%.3lf", (sum - max - min) / 8);//总和去掉最高分去掉最低分除8
	
}