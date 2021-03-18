#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int a[4];
	int max;
	int min;
	int n;
	int k = 0;
	while (scanf("%d", &n) != EOF) {//读入数据
		while (n != 6174) {//不满足条件循环
			min = max = 0;
			k = 0;
			for (int i = 0; i < 4; i++) {//取各位数字
				a[k++]= n % 10;
				n = n / 10;
			}
			sort(a, a + 4, less<int>());//升序排序
			for (int i = 0; i < 4; i++) {//重新构建max和min
				min = min * 10 + a[i];
				max = max * 10 + a[3 - i];
			}
			n = max - min;//计算n
			printf("max:%d min:%d n:%d\n", max, min,n);//格式输出
			
		}
	}
}