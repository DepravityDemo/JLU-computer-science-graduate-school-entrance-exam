#include<stdio.h>
#include<queue>
using namespace std;
int main() {
	int count = 0;//计数变量
	priority_queue<int,vector<int>, greater<int> >myqueue;//优先队列，小根堆
	myqueue.push(1);
	while (count != 100) {
		int cur = myqueue.top();
		myqueue.pop();
		printf("%d ", cur);
		count++;
		myqueue.push(cur * 2);//二倍入队
		if (cur%3==0 && cur %2==0) { continue; }//避免公倍数重复添加
		myqueue.push(cur * 3);//三倍入队
	}
}