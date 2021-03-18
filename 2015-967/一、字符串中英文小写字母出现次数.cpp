#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
int main() {
	char str[100];//存储输入的字符串
	int a[27]; //存储26个字母出现次数
	while (scanf("%s", str) != EOF) {//输入字符串
		memset(a, 0, sizeof(a));//数组置0
		for (int i = 0; str[i] != '\0'; i++) {//判断字母
			if (str[i] >= 'a'&&str[i] <= 'z') {
				a[str[i] - 'a']++;//对应字母统计次数++
			}
			
		}
		for (int i = 0; i < 26; i++) {
			printf("%c:%d\n", i + 'a', a[i]);//输出各字母及出现次数
		}
	}
}