#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;

bool isshowonce(int f[], int size, int n) {
	bool *visit = new bool[size];//访问数组
	memset(visit, 0, sizeof(bool)*size);//初始化
	for (int i = 0; i < size; i++) {//计算所有能组合出的数字
		int num = 0;//初始化为0
		for (int j = 0; j < n; j++) {
			num = num * 2 + f[(i + j) % size];//滚动计算当前n位所表示的数字
		}
		if (visit[num]) {//若当前数字已经被表示过
			delete[]visit;//出现重复，释放visit数组
			return false;//返回flase
		}
		else {
			visit[num] =true;//标记当前数字为已访问
		}
	}
	delete[]visit;//释放标记数组
	return true;//返回true
}

void fun(int n) {
	const int MAXN = pow(2, n);//计算n位数组合种数
	int *f = new int[MAXN];//建立二进制数组
	memset(f, 0, sizeof(int)*MAXN);//初始化为0
	while (1) {//循环
		int j = 0;//梳理二进制数组，执行+1操作
		while (f[j] == 1) {
			f[j++] = 0;
		}
		f[j] = 1;
		if (isshowonce(f, MAXN, n) == true) {//如果当前序列满足条件
			for (int i = 0; i < MAXN; i++) {
				printf("%d ", f[i]);//输出当前序列
			}
			return;//跳出循环
		}
	}
}


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		fun(n);
	}
}