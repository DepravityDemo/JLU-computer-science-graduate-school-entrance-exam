#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
using namespace std;

void reseach(int a[],int x) {//二分查找函数体
	int pre = 0;//前
	int last = 99;//后
	int mid = (pre + last) / 2;//中
	while (pre <=last) {//二分查找过程
		if (a[mid] == x){
			printf("find it!\n");
			return;
	}
		else if (a[mid] > x) {
			last = mid - 1;//中间值比x大，新范围在pre->mid-1;
		}
		else {
			pre = mid + 1;//中间值比小，新范围在mid+1->last;
		}
		mid= (pre + last) / 2;//更新中值
	}
	printf("No find it\n");
}


int main() {
	int a[100] = {
		2,4,6,16,17,22,23,25,29,31,32,34,35,36,37,39,41,43,54,55,56,60,61,64,66,67,68,70,71,74,75,76,78,79,81,82,83,85,86,91,92,95,97,98,99,101,104,105,113,117,119,122,132,134,141,142,143,145,146,147,148,149,150,154,155,159,161,162,163,164,165,166,168,169,170,172,177,180,181,183,188,191,193,195,198,203,204,205,206,207,208,210,211,215,217,218,219,220,225,232
	};
	int x;
	while (scanf("%d", &x) != EOF) {
		reseach(a, x);
	}
}