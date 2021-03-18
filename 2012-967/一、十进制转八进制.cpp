#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
#include<stack>
using namespace std;

int main() {//函数主体
	int n; 
	int sum;
	stack<int>mystack;//栈，用来储存转换后数值
	while (scanf("%d", &n) != EOF) {
		sum = 0;
		int tmp = 1;
		while (n != 0) {
			mystack.push(n % 8);//十进制转八进制过程
			n = n / 8;
		}
		while (!mystack.empty()) {//输出转换后的八进制数
			printf("%d", mystack.top());
			mystack.pop();
		}
		printf("\n");
	}
	
}