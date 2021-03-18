#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int main() {
	int n;
	int step;
	while (scanf("%d", &n) != EOF) {
		step = 1;//本应从0开始记录，但题目给的示例输入22输出16是从1开始计的，考生情根据实际情况调整
		while (n != 1) {//n不等于1时循环
			if (n % 2 == 0) {
				n = n / 2; 
			}//n为偶数时除以2
			else {
				n = 3 * n + 1;//n为奇数*3+1；
			}
			step++;//计步+1
		}
		printf("%d\n", step);//输出步数
	}
	
}