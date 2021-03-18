#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
int main() {
	const int n = 4;
	int a[n] = { 1,2,3,4 };
	int b[n] = { 0 };
	int x;
	scanf("%d", &x);
	for (int i = 0; i < pow(2, n); i++) {//一共2^n种组合
		int cot = 0;//统计当前选中元素数
		b[0]++;//二进制数组+1
		for (int j = 0; j < n - 1;j++) {//整理二进制数组，够2的进位
			b[j + 1] += b[j] / 2;
			b[j] = b[j] % 2;
		}
		for (int j = 0; j < n; j++) {//判断当前二进制数组选中元素个数
			if (b[j] == 1)cot++;
		}
		if (cot == x) {//当前集合选中元素个数符合要求则按格式输出
			printf("{ ");
			for (int j = 0; j < n; j++) {
				if (b[j] == 1)printf("%d ", a[j]);
			}
			printf("}");
		}
	}
}