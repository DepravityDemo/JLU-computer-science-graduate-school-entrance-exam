#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

/*
定义一数列k[n]
		|1			n=1;
k[n]=	|-2k(n-1)+1 n为偶数
		|-3k(n-1)+1	n为奇数
*/
//本题应该是题目有问题。数量级达到2的100次方以上，且没有分母进行化简。答案结果已经溢出，仅做思路参考。
int main() {
	long long a[101];//定义数组储存序列
	
	a[1] = 1;//定义首项
	long long sum = 1;//定义和
	for (int i = 2; i <=100; i++) {
		if (i % 2 == 0) {//i为偶数
			a[i] = a[i - 1] * -2 + 1;
		}
		else {//i为奇数
			a[i] = a[i - 1] * 3 + 1;
		}
		sum += a[i];//累加求和
	}
	printf("%lld\n", sum);//输出答案
}
