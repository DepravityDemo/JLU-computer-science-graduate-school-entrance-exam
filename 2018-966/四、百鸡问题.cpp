#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int  main() {
	int jz = 1;//将价钱等比例扩大三倍，可以省去小数计算
	int jm = 9;
	int jw = 15;
	for (int i = 0; i < 21; i++) {//只买鸡翁最多20只
		for (int j = 0; j < 34; j++) {//只买母鸡最多33只
			int k = 100 - i - j;//小鸡数目是100-公鸡-母鸡（题目要求一共一百只鸡）
				if (i*jw + j * jm + k * jz == 300) {//因价格扩大3倍，钱数等比例扩大三倍
					printf("%d %d %d\n", i, j, k);//输出可能结果
				}
			
		}
	}
}