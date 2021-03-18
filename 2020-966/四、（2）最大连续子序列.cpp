#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct Node {
	int data;
	Node *next;
}*List;


void del(List head) {//程序主体
	List p = head->next;
	List qpre;//遍历指针前驱
	while (p != NULL) {
		List q = p->next;//从p后一元素开始遍历整个链表
		qpre = p;//初始化q前驱
		while (q!= NULL) {//未到链表尾循环
			if (p->data == q->data) {//如果pq相等，则删除q节点
				qpre->next = q->next;//将q从链表中分离
				free(q);//释放q
				q = qpre->next;//q指向回链表，在此qpre不用进行改变
				continue;//进行下次循环
			}
			qpre = q;//qpre后移
			q = q->next;//q后移
		}
		p = p->next;//p后移
	}
}

List head = (List)malloc(sizeof(Node));

void build() {//生成原链表
	List p1 = head;
	const int n = 10;
	int a[n] = { 4,7,2,5,7,6,9,12,2,3 };
	List p;
	for (int i = 0; i < n; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}

void print(List head) {//输出链表
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
	del(head);//删除程序
	print(head);
}