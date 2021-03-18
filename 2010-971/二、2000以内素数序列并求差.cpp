#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
using namespace std;
bool isprime(int n) {
	if (n < 2)return false;
	for (int i = 2; i <= n / 2; i++) {
		if (n%i == 0)return false;
	}
	return true;
}


int main() {
	int arr[1000];//素数数组
	int ans[1000];//结果数组
	bool prime[2001];//是否是素数标记
	int k = 0;
	memset(prime, true, sizeof(prime));
	for (int i = 2; i <= 2000; i++) {//素数筛法求素数
		if (prime[i]) {
			arr[k++] = i;
			for (int j = i * i; j <=2000; j += i) {//某数是素数，他的倍数都不是素数
				prime[j] = false;//标记素数标记为flase
			}
		}
	}
	for (int i = 0; i < k-1; i++) {//逐项求差并输出
		ans[i] = arr[i + 1] - arr[i];
		printf("%d ", ans[i]);
	}

}