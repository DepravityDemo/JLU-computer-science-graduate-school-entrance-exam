#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>

typedef struct Node {
	int data;
	Node *next;
}node, *List;

List head = (List)malloc(sizeof(Node));
List head2 = (List)malloc(sizeof(Node));
void build() {
	int a[5] = { 1,3,5,17,91 };
	List p, p1;
	p1 = head;
	for (int i = 0; i < 5; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}
void build2() {
	int a[5] = { 2,3,6,17,22 };
	List p, p1;
	p1 = head2;
	for (int i = 0; i < 5; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}

void sort(List head) {
	List p = head->next;//遍历指针
	while (p != NULL) {//冒泡排序链表
		List q = p->next;
		while (q != NULL) {
			if (p->data > q->data) {//如果p大于q则两者互换
				int tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}
			q = q->next;//指针后移
		}
		p = p->next;//指针后移
	}
}

List merge(List head1, List head2) {//合并
	List newhead = (List)malloc(sizeof(Node));//初始化新链表头
	List p = head1->next;//head1遍历指针
	List q = head2->next;//head2遍历指针
	newhead->next = NULL;//初始化 尾结点
	List k = newhead;//新链表指针
	while (p != NULL && q != NULL) {//p和q都不为空循环
		if (p->data <= q->data) {//将较小的插入到新链表
			if (q->data == p->data) {//如果p和q相等，插入p不插入q
				q = q->next;
			}
			k->next = p;//将p尾插法插入新链表
			k = p;
			p = p->next;
			
		}
		else {
			k->next = q;//将q尾插法插入新链表
			k = q;
			q = q->next;
		}
	}
	if (p != NULL) {//将剩余链表接入
		k->next = p;
	}
	if (q != NULL) {//将剩余链表接入
		k->next = q;
	}
	return newhead;//返回新头
}


int main() {
	build();
	build2();
	sort(head);
	sort(head2);
	printf("\n");

	List p= merge(head, head2)->next;
	while (p != NULL) {//输出链表
		printf("%d ", p->data);
		p = p->next;
	}



}