#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
using namespace std;


void arrsort(int a[], int n) {//函数主体
	int i = 0;
	int j = n - 1;
	while (i < j) {//分离奇偶数
		while (a[i] % 2 == 0) { i++; }//寻找第一个奇数
		while (a[j] % 2 != 0) { j--; }//寻找第一个偶数
		if (i < j) {//交换奇偶数位置
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}

	sort(a, a + i, less<int>());//偶数升序
	sort(a+i, a +n, less<int>());//奇数升序

}

int main() {
	int a[100] = {
		93,28,4,16,52,8,65,9,79,55,70,20,59,75,87,9,19,1,39,19,2,24,76,20,36,87,44,3,77,93,55,96,13,72,44,4,69,15,41,78,56,35,13,75,9,55,40,60,33,55,28,100,26,38,62,31,4,81,28,33,31,91,89,10,61,96,26,22,48,90,1,24,54,19,43,90,37,48,1,63,81,19,36,76,25,13,84,2,70,55,42,81,69,2,4,77,89,23,68,47
	};
	arrsort(a,100);
	for (int i = 0; i < 100; i++) {
		printf("%d ", a[i]);
	}
}