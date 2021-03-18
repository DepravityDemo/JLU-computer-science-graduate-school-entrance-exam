#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
using namespace std;


int * cot(char s[], char a[], int n) {
	int *ans = new int[n];//建立和一维字符数组等长的答案数组
	memset(ans, 0, sizeof(int)*n);//数组元素置0，因ans为指针类型，故sizeof未使用sizeof(ans),这样会导致只有一个元素被赋值
	int len = strlen(s);//计算字符串长度
	for (int i = 0; i < len; i++) {//遍历字符串
		for (int j = 0; j< n; j++) {//在字符数组中查找是否有符合的
			if (s[i] == a[j]) {
				ans[j]++;//有符合的对应计数数组++
				break;//判断下一位
			}
		}
	}
	return ans;//返回计数数组指针
}





int main() {
	char str[100];
	char a[4] = { 'a','b','c' };
	int *ans=NULL;
	while (scanf("%s", str) != EOF) {
		ans = cot(str, a, 3);//调用函数体
		for (int i = 0; i < 3; i++) {//输出结果
			printf("%c:%d\n", a[i], ans[i]);
		}
	}
	
}