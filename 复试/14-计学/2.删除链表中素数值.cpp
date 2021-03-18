#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
using namespace std;
//无注释部分仅为测试用，考试时候不用写，只写函数主体就可以
typedef struct Node {//结构体定义
	int data;
	Node *next;
}*List;
bool isprime(int n) {//判断素数
	if (n < 2)return false;//如果n小于2，返回false
	else {
		for (int i = 2; i <=n/2; i++) {//判断是否能被非1和本身数整除
			if (n%i == 0) {
				return false;//能被整除返回false
			}
		}
	}
	return true;//不能整除返回true
}

void del(List head) {//函数主体
	List ppre = head;//定义p前驱
	List p = head->next;//定义链表遍历指针p
	while (p != NULL) {//当遍历没到链表尾循环
		if (isprime(p->data)) {//如果当前节点数据是素数，则删除
			ppre->next = p->next;
			free(p);//释放当前节点
			p = ppre->next;//更新当前节点位置
			continue;//进入一下轮循环
		}
		ppre = p;//p前驱后移
		p = p->next;//p后移
	}
}
List head = (List)malloc(sizeof(Node));

void build() {
	List p1 = head;
	const int n = 10;
	int a[n] = { 4,7,2,5,8,6,9,12,11,3 };
	List p;
	for (int i = 0; i < n; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}

void print(List head) {
	List p = head->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	build();
	print(head);
	del(head);
	print(head);

}
