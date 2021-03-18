#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>

void Sort(int a[],int n) {
	int i = 0;
	int j = n - 1;
	while (i < j) {
		while (a[i] % 2 != 0)i++;
		while (a[j] % 2 == 0)j--;
		if (i < j) {
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}

}



int main() {
	int a[10] = { 7,2,4,8,5,7,6,9,16,3};
	Sort(a,10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
}