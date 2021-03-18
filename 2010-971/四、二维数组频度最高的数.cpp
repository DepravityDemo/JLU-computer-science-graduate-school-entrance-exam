#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<map>;
using namespace std;

int main() {
	int a[5][5] = {
		3,2,4,5,1,
		10,9,3,4,2,
		8,7,6,7,7,
		3,3,4,1,2,
		4,5,3,1,1,
	};
	map<int, int>mymap;//第一维是元素值，第二维是出现次数
	for (int i = 0; i < 5; i++) {//题目未给定元素取值范围，固使用map映射以节省空间
		for (int j = 0; j < 5; j++) {
			mymap[a[i][j]]++;
		}
	}
	map<int, int>::iterator it;//定义map迭代器
	int max=0;//储存出现次数最大值
	int maxindex;//储存出现次数最大值的元素
	for (it=mymap.begin(); it != mymap.end(); it++) {//遍历map寻找最大值
		if (it->second > max) {
			maxindex = it->first;//更新最大值，与最大值元素
			max = it->second;
		}
	}
	printf("%d", maxindex);//输出最大值元素的值
}
