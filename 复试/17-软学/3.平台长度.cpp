#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;


int main() {
	int a[10] = { 1,2,2,3,3,3,4,4,4,4 };
	int i = 0;
	int max = 0;//最大平台数
	int cot = 1;//平台计数变量
	int key = a[0];//设置第一个数为key
	for (int i = 1; i <10; i++) {
		if (a[i] == key) {//若当前数与平台key相等，则cot++；
			cot++;
		}
		else {
			if (cot > max)max = cot;//如果当前cot大于max，更新最大平台数
			key = a[i];//更新key
			cot = 1;
		}
	}
	if (cot > max)max = cot;//避免最后一位也是平台导致未能更新到max中
	printf("%d", max);
	return 0;
}