#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>


int main() {
	const int n = 10;
	const int m = 4;
	int a[n] = { 1,2,3,8,7,6,5,4,3,2 };//test data
	int *ans = new int[n];//新建答案数组
	int k = 0;//答案数组指针
	int i = m-1, j =m;//i指向前m最大值，j指向后n-m最大值
	while (i >= 0&&j<n) {//没到边界时循环
		if (a[i]>a[j]) {//较大的进入数组
			ans[k++] = a[i--];
		}
		else if (a[i] == a[j]) {
			ans[k++] = a[i--];
			j++;//去重
		}
		else {
			ans[k++] = a[j++];
		}
	}
	while (i >=0) {//加入后续元素
		ans[k++] = a[i--];
	}
	while (j <n) {//加入后续元素
		ans[k++] = a[j++];
	}
	for (int i = 0; i < k; i++) {//输出答案
		printf("%d ", ans[i]);
	}
}