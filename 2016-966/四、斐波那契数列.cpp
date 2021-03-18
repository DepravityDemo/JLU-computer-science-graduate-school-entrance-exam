#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>



int fun(int n) {
	if (n == 1 or n == 2) {
		return 1;
	}
	else return fun(n - 1) + fun(n - 2);
}



int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%d\n",fun(n));
	}
}