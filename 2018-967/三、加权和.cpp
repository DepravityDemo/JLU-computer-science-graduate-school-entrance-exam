#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int jqh(int a[], int n) {
	int i = 0;//左指针
	int j = n - 1;//右指针
	int sum=0;//加权和
	int k = 1;//权重
	while (i <=j) {//使用贪心算法每次寻找当前最小数去乘权重
		if (a[i] > a[j]) {//右端数字较小
			sum += a[j] *( k++);
			j--;
		}
		else {
			sum += a[i] * (k++);//左端数字较小
			i++;
		}

	}
	return sum;//返回加权和
}



int main() {
	int a[8] = { 7,4,5,3,2,8,9,6 };
	printf("%d\n",jqh(a, 8));
}