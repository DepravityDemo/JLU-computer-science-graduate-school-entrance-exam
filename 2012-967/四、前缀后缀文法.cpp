#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
#include<stack>
using namespace std;

int main() {
	char str[100];//储存字符串
	stack<char>s;//符号栈
	while (scanf("%s", str) != EOF) {//读入字符串
		for (int i = 0; str[i] != '\0'; i++) {//遍历字符串
			if (str[i] == '+' || str[i] == '*') {//如果符号为+或*压栈
				s.push(str[i]);
			}
			else if (str[i] == ')') {//遇到右括号时原样输出，并输出栈顶符号，栈顶符号出栈
				printf("%c", str[i]);
				printf("%c", s.top());
				s.pop();
			}
			else {
				printf("%c", str[i]);//其余字符原样输出
			}
		}
	}
}

//test data
//+(*(a, +(a, a)), a)