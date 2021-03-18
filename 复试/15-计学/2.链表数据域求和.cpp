#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	Node*next;
}*List;


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
	p1->next = head;//建立测试循环单链表
}

void print(List head) {
	List p = head->next;
	while (p->next != head) {
		printf("%d ", p->data);
		p = p->next;
	}
}

int sum(List head) {
	List p = head->next;//遍历指针
	int sum = 0;//记录和
	while (p->next != head) {//下一个节点不是头结点说明不是末尾
		sum += p->data;//累加
		p = p->next;//遍历指针后移
	}
	return sum;//返回和
}


int main() {
	build();
	print(head);
	printf("\n");
	printf("%d", sum(head));
}

