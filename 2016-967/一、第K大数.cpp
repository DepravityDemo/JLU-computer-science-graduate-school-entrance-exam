#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;	
const int m = 8;
void fun1(int a[], int k) {
	sort(a, a + m, greater<int>());//对a排序
	printf("%d\n", a[k - 1]);//输出第K大数字
}
int main() {

	int a[m] = { 7,4,2,5,3,6,8,0 };
	int k;
	while (scanf("%d", &k) != EOF) {
		fun1(a, k);
	}
}