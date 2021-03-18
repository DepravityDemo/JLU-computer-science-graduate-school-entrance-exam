#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

int Del(int a[], int n, int x) {//函数主体
	int i = 0;//左边界
	int j = n-1;//右边界
	int mid = (i + j) / 2;//中值
	while (i < j) {//边界未相交时
		if (a[mid] == x) {//如果找到该元素
			for (int k = mid; k < n-1; k++) {//后边数据前移一位相当于删除
				a[k] = a[k + 1];
			}
			n--;//总长减1
			return n;//返回长度
		}
		else if (a[mid] > x) {//中值比要删除数据大，将右边界设置为mid-1
			j = mid - 1;
		}
		else {
			i = mid + 1;//中值比要删除数据小，将左边界设置为mid+1
		}
		mid = (i + j) / 2;//更新中值
	}
	printf("No found it!");//边界相交还未找到，查找失败，返回未找到。
	return n;
}


int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10};//测试数据考试是不用写，只需要写上边函数主体
	int x,n;
	n = 10;
	while (scanf("%d", &x) != EOF) {
		n=Del(a,n,x);
		for (int i = 0; i < n; i++) {//输出当前数组
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	
}