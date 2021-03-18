#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	Node*next;
}*List;

void insert(List head) {
	List p = head->next->next;//p指向要插入节点的后一节点
	List ppre = head->next;//ppre指向要插入节点的后一节点
	while (p != NULL) {//遍历链表
		List q = (List)malloc(sizeof(Node));//新建节点
		q->data = p->data + ppre->data;//计算节点值
		ppre->next = q;//插入
		q->next = p;
		ppre = p;
		p = p->next;
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
}

int main() {
	build();
	print(head);
	printf("\n");
	insert(head);
	print(head);
}
