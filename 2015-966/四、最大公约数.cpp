#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>.
#include<string.h>
#include<stack>
using namespace std;


int gcd(int a, int b) {
	if (a%b == 0)return b;//如a能整除b则返回b
	else {
		return gcd(b, a%b);//递归求解
	}
}

int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) != EOF) {
		printf("%d\n", gcd(a, b));
	}
}