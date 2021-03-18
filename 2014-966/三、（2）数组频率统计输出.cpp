#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<map>
using namespace std;
void fun(int a[]) {//函数主体
	map<int, int>mymap;//建立映射
	for (int i = 0; i < 200; i++) {//遍历数组，对应映射值++
		mymap[a[i]]++;
	}
	map<int, int>::iterator it;//定义map迭代器
	for (it = mymap.begin(); it != mymap.end(); it++) {//输出结果
		printf("%d 出现的次数是 %d\n", it->first, it->second);
	}
}


int main() {
	int a[200] = {
		66,69,14,99,95,2,96,69,49,65,89,35,77,100,78,93,27,29,38,86,35,4,98,86,27,68,19,24,65,10,98,17,42,20,18,98,19,25,72,13,52,19,10,94,71,1,55,12,50,42,30,93,28,19,20,71,67,52,96,28,26,62,83,72,89,7,87,64,92,84,78,86,74,77,17,32,42,98,13,34,26,14,39,41,65,50,81,47,26,83,16,3,66,48,88,18,92,98,36,89
	};
	fun(a);
	
}