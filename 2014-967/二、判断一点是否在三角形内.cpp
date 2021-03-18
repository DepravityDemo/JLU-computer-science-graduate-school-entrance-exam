#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

int main() {
	int a[100];
	int b[100];
	int c[100];
	int m, int n;
	int i = 0, j = 0; 
	while (scnf("%d %d", &m, &n) != EOF) {
		while (m != 0) {
			a[i++] = m % 10;
			m = m / 10;
		}
		while (n != 0) {
			b[j++] = n % 10;
			n = n / 10
		}
		;
	}
}