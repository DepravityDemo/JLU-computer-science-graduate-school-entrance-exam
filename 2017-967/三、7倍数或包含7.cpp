#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
using namespace std;
bool inc(int n) {//判断各位数字中是否包含7
	while (n != 0) {//逐位取数字并判断
		if (n % 10 == 7) {
			return true;
		}
		n = n / 10;
	}
	return false;//不包含返回false
}
void print(int k) {//函数主体
	int flag=1;//符号输出控制
	for (int i = 7; i < k; i++) {//第一数字最小为7故直接从7开始
		if (i % 7 == 0 || inc(i)) {//当前数字包含7或能被7整除
			if (flag) {
				printf("%d",i);//第一个元素前不输出逗号
				flag = 0;
			}
			else {
				printf(",%d",i);;//后续元素前不输出逗号
				
			}
			
		}
	}
}


int main() {
	int k;
	while (scanf("%d", &k) != EOF) {//读入数据
		print(k);//执行函数
	}
}