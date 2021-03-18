#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<iostream>
using namespace std;
typedef struct Node {
	int data;
	Node*next;
}*List;
List head = (List)malloc(sizeof(Node));

void build() {
	List p1 = head;
	const int n = 10;
	int a[n] = { 4,7,2,5,8,6,9,4,11,3 };
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

}

void del(List head) {//函数主体
	List p;//遍历指针
	List max, maxpre;//指针指向max节点与max节点前驱，指向前驱为方便删除
	max = head->next;//假设第一节点就是最大节点
	maxpre = head;//前驱为头结点
	p = head->next;//p开始遍历链表
	while (p->next!= NULL) {//p后继节点不为空时遍历
		if (p->next-> data > max->data) {//若p后继节点数据比现有max大，更新现有max，maxpre
			max = p->next;
			maxpre = p;
		}
		p = p->next;//p后移
	}
	head->data = max->data;//头结点数据域填充最大值
	maxpre->next = max->next;//将最大值从链表中删除
	free(max);//释放最大值节点
}

int main() {
	
	build();
	print(head);
	printf("\n");
	del(head);
	printf("%d\t", head->data);//单独输出头节点，答案不要求仅做测试用
	print(head);

}