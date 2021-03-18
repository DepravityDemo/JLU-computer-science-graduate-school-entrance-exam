#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {//题目未给出具体项数，按100解答
	long long a[101];//定义答案数组
	a[1] = 1;//初始化第一位第二位
	a[2] = 2;
	for (int i = 3; i <= 100; i++) {
		if (i % 2 != 0) {//奇数处理
			a[i] = a[i - 1] + a[i - 2];
		}
		else {//偶数处理
			a[i] = a[i - 1] - a[i - 2];
		}
	}
	sort(a+1, a + 101, less<long long>());//升序排序
	for (int i = 1; i <= 100; i++) {//输出结果
		printf("%lld ", a[i]);
	}
}