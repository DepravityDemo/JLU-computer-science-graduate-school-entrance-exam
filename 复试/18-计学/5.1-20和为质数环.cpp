#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

bool isprime(int n) {
	if (n < 2)return false;
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int visit[21];
int ans[20];
bool check(int step) {//检查是否符合要求
	if (isprime(ans[step - 1] + ans[step]))return true;//符合要求返回true
	else if (step == 19) {//当前为最后一个，要看与第一个是否匹配
		if(isprime(ans[19]+ans[0]))return true;
	}
	else return false;//不匹配返回false
}

int flag = 0;
void dfs(int step) {//深度优先遍历
	if (step == 20) {//遍历结束，输出结果
		for (int i = 0; i < 20; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		flag = 1;//题目要求输出一组，发现一组后返回。
	}
	if (flag)return;
	for (int i = 2; i <= 20; i++) {//遍历所有数字（1）默认已经遍历
		if (!visit[i]) {//如果当前数字未使用
			ans[step] = i;//当前位赋值当前数字
			visit[i] = 1;//标记已访问
			if (check(step)) {//若合法，对下一位进行DFS；
				dfs(step + 1);
			}
			visit[i] = 0;//标记本数字为未访问回溯
		}
	}
	
}


int main() {
	memset(visit, 0, sizeof(visit));//初始化数字访问标记数组
	memset(ans, 0, sizeof(ans));//初始化答案数组
	ans[0] = 1;//设置答案第一位为1
	visit[1] = 1;//标记为已访问
	dfs(1);//dfs进行遍历
}



