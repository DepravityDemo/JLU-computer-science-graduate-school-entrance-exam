#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
#include<stack>
using namespace std;

int main() {
	char arr[100];//存储字符数组
	while (scanf("%s", arr) != EOF) {
		int len = strlen(arr);//获取字符串长度
		if (arr[0] != 'a' || arr[len - 1] != 'd') { printf("N"); continue; }//头尾不符合的直接输出N，判断下一组
		int k = 0;
		while (arr[k] == 'a') {//统计字符a出现次数
			k++;
		}
		while (arr[k] == 'b') {//统计字符b出现次数
			k++;
		}
		while (arr[k] == 'c') {//统计字符c出现次数
			k++;
		}
		while (arr[k] == 'd') {//统计字符d出现次数
			k++;
		}
		if (k == len) {//abcd按序出现时k才与len相等
			printf("Y\n");
		}
		else {
			printf("N\n");
		}
	}
}