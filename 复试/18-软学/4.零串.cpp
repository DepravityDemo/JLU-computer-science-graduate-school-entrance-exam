#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main() {
	char str[100];
	int cot;//零串长度遍量
	int totalcot;//零串字符变量
	while (scanf("%s", str) != EOF) {
		cot = 0;//计数变量
		totalcot = 0;//零串数量
		for (int i = 0; i < strlen(str); i++) {//遍历字符串
			while (str[i] == '0') {//计算0串长度
				cot++;//奇数变量++
				i++;//i后移
			}
			if (cot > 1){//当前是零串
			totalcot++;//零串数量++
			}
			cot = 0;//零串长度奇数变量清零
		}
		if (totalcot >= 2) {//零串数量大于等于2，符合要求
			printf("1\n");

		}
		else printf("0\n");
	}
}