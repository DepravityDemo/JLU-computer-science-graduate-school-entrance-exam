#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

using namespace std;

bool isconsist(int n) {//函数主体
	while (n != 0) {
		int tmp = n % 10;//取n最后一位
		if (!(tmp == 1 || tmp == 3 || tmp == 5 || tmp == 7 || tmp == 9)) {//判断当前位是否包含1,3,5,7,9
			return false;
		}
		n = n / 10;//n移动一位
	}
	return true;
}


int main() {
	int n;
	scanf("%d", &n);
	if (isconsist(n)) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}