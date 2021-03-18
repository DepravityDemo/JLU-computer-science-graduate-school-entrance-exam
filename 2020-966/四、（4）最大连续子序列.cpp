#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAXN = 100;
int max(int a, int b) {//求两者较大的
	if (a > b)return a;
	else return b;
}
int main() {
	int a[10] = { 7,1,2,3,-5,6,4,-8,0,2};//test arr
	int dp[10];//dp数组，dp[i]表示以
	memset(dp, 0, sizeof(dp));//初始化dp数组
	int Max = 0;//储存最大值
	int tmp = 0;
	int head=0, tail=0;
	for (int i = 0; i < 10; i++) {//遍历数组
		if (i == 0) {
			dp[i] = a[i];//初始化第一个dp元素
		}
		else {
			if (dp[i - 1] + a[i] < a[i]) {//如果当前节点比之前序列和大
				dp[i] = a[i];//dp[i]更新为当前节点
				head = i;//记录头节点
			}
			else {
				dp[i] = dp[i - 1] + a[i];//如加上此节点后dp[i]变大，则累加
			}
		}
		if (dp[i] > Max) {//判断当前段子序列和合最大子序列和大小
			Max = dp[i];//如果当前大，则储存为Max
			tail = i;//标记为尾节点
		}
	}
	printf("起始于：%d 终止于：%d 元素个数：%d\n", head,tail,tail-head+1);//输出元素个数
	for (int i = head; i <= tail; i++) {//输出最大子序列
		printf("%d ", a[i]);
	}
}