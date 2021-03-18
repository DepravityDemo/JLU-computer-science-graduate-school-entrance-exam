#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

bool ispriem(int n) {
	if (n < 2)return false;
	for (int i = 2; i <= n / 2; i++) {
		if (n%i == 0)return false;
	}
	return true;
}



int main() {
	int count=0;
	int i=2;
	while(count!=20){//计数变量
		if (ispriem(i) && ispriem(i + 2)) {//i与i+2同为奇数
			printf("(%d,%d) ", i, i + 2);//输出答案
			count++;//计数变量+1
		}
		i++;//i++
	}
}