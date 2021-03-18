#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<queue>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	priority_queue<int,vector<int>,greater<int> > q;//建立优先队列，大的优先级低//这里保证队列中最小值在top
	q.push(1);//将1压入优先队列
	int cot = 1;//计数变量
	while (cot != 100) {//数量没达到100
		int tmp = q.top();//队顶出队
		printf("%d ",tmp);//输出
		cot++;//计数变量++
		q.pop();//出队
		q.push(tmp * 2);//将2x压入队
		if (tmp * 3 % 6 == 0)continue;//如果tmp*3为6的倍数，那么将和2x重复，固跳过
		q.push(tmp * 3);//压入3x
	}
	
}