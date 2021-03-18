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

void jj(List head1,List head2) {//求交集
	List p = head1->next;//第一个链表指针
	List q = head2->next;//第二个链表指针
	List newhead= (List)malloc(sizeof(Node));//建立新头
	newhead->next = NULL;//初始化新链表尾
	List k = newhead;//新头指针
	while (p != NULL && q != NULL) {//遍历链表
		if (p->data == q->data) {//节点数值相等，则加入新链表
			List tmp = (List)malloc(sizeof(Node));//新建节点为了防止破坏原链表结构
			tmp->data = p->data;
			k->next = tmp;
			k = tmp;
			p = p->next;
			q = q->next;
		}
		else if (p->data > q->data) {//q较小则q向后移找更大的
			q = q->next;
		}
		else {//p较小则p向后移找更大的
			p = p->next;
		}
	}
	k->next = NULL;//创建表尾
	p = newhead->next;//遍历指针
	while (p != NULL) {//输出交集链表
		printf("%d ", p->data);
		p = p->next;
	}
}

void bj(List head1, List head2) {
	List p = head1->next;//第一个链表指针
	List q = head2->next;//第二个链表指针
	while (q != NULL) {//将第二个链表插入到第一个链表中
		while (p->next != NULL&&p->next->data < q->data) {//寻找插入位置
			p = p->next;
		}
		if (p->next == NULL) {//若已到达表尾，直接将q接入链表一尾部
			p->next = q;
		}
		if (p->next->data == q->data) {//若两节点相等，则跳过本节点插入
			q = q->next;
			continue;
		}
		List cur = q;//储存q
		q = q->next;//q后移
		cur->next = p->next;//将cur尾插法插入到p中
		p->next = cur;//插入
		p = cur;//更新尾指针
	}
	p = head1->next;//遍历链表输出
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}


int main() {
	build();
	build2();
	jj(head, head2);
	printf("\n");
	bj(head, head2);




}