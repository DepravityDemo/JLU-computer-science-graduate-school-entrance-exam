#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

void bj(int a[], int m, int b[], int n) {//求并集主函数
	int max;//保存长度最大值
	if (m > n) {
		max = m;
	}
	else max = n;
	int *ans = new int[max];//并集数组元素大小为两个数组元素较多那个
	memset(ans, 0, sizeof(ans));//初始化答案数组为0
	for (int i = 0; i < m; i++) {
		ans[i] = a[i];//将数组1写入答案数组
	}
	for (int i = 0; i < n; i++) {//两集合作并集
		if (ans[i] or b[i]) {
			ans[i] = 1;
		}
		else ans[i] = 0;
	}
	for (int i = 0; i < max; i++) {//输出答案
		printf("%d ", ans[i]);
	}
}

void jj(int a[], int m,int b[], int n) {//求交集
	int min;//求两集合长度较小者
	if (m > n) {
		min = n;
	}
	else {
		min = m;
	}
	int *ans = new int[min];//新建交集数组
	memset(ans, 0, sizeof(ans));//初始化交集数组
	for (int i = 0; i < min; i++) {//a,b集合做交集
		ans[i] = a[i] && b[i];
	}
	for (int i = 0; i < min; i++) {
		printf("%d ", ans[i]);//输出答案
	}
}

int main() {
	int a[9] = { 0,0,0,1,1,0,1,0,1 };
	int b[7] = { 0,0,1,1,1,1,1 };
	 bj(a, 9, b, 7);
	 printf("\n");
	 jj(a, 9, b, 7);
}