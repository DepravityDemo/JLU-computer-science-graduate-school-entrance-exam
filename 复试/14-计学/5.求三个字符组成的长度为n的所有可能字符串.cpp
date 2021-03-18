#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
int sum = 0;
void DFS(int n, int step,char str[]) {//深度优先遍历求解
	if (step == n) {//符合位数要求
		str[n] = '\0';//添加字符串结尾
		sum++;//计数变量
		printf("%s\n", str);//输出字符串
		return;//返回上一层
	}
	str[step] = 'A';//此位从A开始
	DFS(n, step + 1, str);
	str[step] = 'B';//此位从B开始
	DFS(n, step + 1, str);
	str[step] = 'C';//此位从C开始
	DFS(n, step + 1, str);//回溯保证了输出所有可能性
}



int main() {
	int n;
	char str[100];
	while (scanf("%d", &n) != EOF) {
		DFS(n,0,str);//深度遍历求解
		printf("the number of answer is :%d\n", sum);
	}
}