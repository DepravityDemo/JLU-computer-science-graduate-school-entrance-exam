#define _CRT_SECURE_NO_DEPRECATE //保证VS不检测scanf错误
#include<stdio.h>



void plat(int a[], int n) {//函数体
	int key = a[0];//哨兵节点，表示平台开始元素值
	int len=1;//平台长度,a[0]已存在于平台，固设置为1，或此处设置为0，for循环设置i从0开始
	int max=0;//最大平台长度
	for (int i = 1; i < n; i++) {
		if (a[i] == key) {//与平台首元素值相等，平台长度++
			len++;
		}
		else {//与平台首元素不等
			if (len > max) {//比较当前平台长度与最大平台长度，保存最大值
				max = len;
			}
			key = a[i];//更新平台首元素值
			len = 1;//平台长度归1
		}
	}
	printf("%d\n", max);
}








int main() {
	const int n = 11;
	int a[n] = { 9,8,8,8,8,7,3,3,1,1,1 };// test data;
	plat(a, n);//调用函数体
}

