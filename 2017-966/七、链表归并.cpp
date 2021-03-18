#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;

typedef struct Node {
	int data;
	Node*next;
}*List;
List head1 = (List)malloc(sizeof(Node));
List head2 = (List)malloc(sizeof(Node));
void build() {
	List p1 = head1;
	const int n = 3;
	int a[n] = { 1,3,4};
	List p;
	for (int i = 0; i < n; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}
void build2() {
	List p1 = head2;
	const int n = 3;
	int a[n] = { 1,5,3 };
	List p;
	for (int i = 0; i < n; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}
void sort(List head) {
	List p = head->next;
	List q = p->next;
	while (p->next != NULL) {
		q = p->next;
		while (q != NULL) {
			if (p->data > q->data) {
				int tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}
			q = q->next;
		}
		p = p->next; 
	}
}

List UnionSet(List q, List p) {
	sort(p);//对p排序
	sort(q);//对q排序
	List newhead = (List)malloc(sizeof(Node));//建立新链表节点
	newhead->next = NULL;//表尾为NULL
	List k = newhead;//k为尾插指针
	p = p->next;//移到第一个数据节点
	q = q->next;
	while (q != NULL && p != NULL) {//归并排序
		if (q->data < p->data) {//q小时，将q插入new链表
			List cur = q;
			q = q->next;//尾插法插入
			cur->next = k->next;
			k->next = cur;
			k = cur;
		}
		else {
			List cur = p;//p小时，将p插入新链表
			if (p->data == q->data) {
				q = q->next;//p，q值相同时跳过
			}
			p = p->next;//尾插法插入
			cur->next = k->next;
			k->next = cur;
			k = cur;

		}
	}
	if (q != NULL) {//链接剩余链表
		k->next = q;
	}
	else if (p != NULL) {
		k->next = p;
	}
	return newhead;//返回新头
}

int main() {
	build();
	build2();
	List newhead= UnionSet(head1, head2);
	List p = newhead->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}

}