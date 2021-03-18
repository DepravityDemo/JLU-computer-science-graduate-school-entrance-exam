#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
	int fz = 2;//分子
	int fm = 1;//分母
	int tmp;
	int n = 20;
	while (n--) {//计数变量
		printf("%d/%d ", fz, fm);//输出答案
		tmp = fm + fz;//临时储存分子+分母
		fm = fz;//fm等于上一项分子
		fz = tmp;//fz等于上一项分母加分子
	}
}