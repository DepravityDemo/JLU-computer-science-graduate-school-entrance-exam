#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	Node *next;
}node, *List;
List head1 = (List)malloc(sizeof(Node));
List head2 = (List)malloc(sizeof(Node));
void build() {
	List ppre, p, q, qpre;
	ppre = head1;
	const int m = 6;
	const int n = 5;
	qpre = head2;
	int a[m] = { 1,2,4,5,6,12};
	int b[n] = {2,3,7,8,11 };
	for (int i = 0; i < m; i++) {
		List p = (List)malloc(sizeof(Node));
		p->data = a[i];
		ppre->next = p;
		ppre = p;

	}
	ppre->next = NULL;
	for (int i = 0; i < n; i++) {
		List q = (List)malloc(sizeof(Node));
		q->data = b[i];
		qpre->next = q;
		qpre = q;
	}
	qpre->next = NULL;
}
void print(List head) {
	List p = head->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	return;
}

void merge(List head1, List head2) {//函数主体，其余不是答案部分，仅做测试用
	List p, q;
	p = head1->next;//p为第一个链表指针 
	head1->next = NULL;//将head1作为答案头
	q = head2->next;//q为第二个链表指针
	while (p != NULL && q != NULL)//改造第一个链表
	if (q->data < p->data) {//选择最小值，头插到head1之后，小的值再链表后端
		List cur = q;//临时储存q
		q = q->next;//q指向下一节点
		cur->next = head1->next;//对当前节点头插
		head1->next = cur;
	}
	else {
		List cur = p; //临时储存p
		p = p->next;//p指向下一节点
		if (p->data == q->data) {//当p与q节点值相同时，跳过q当前节点
			q = q->next;
		}
		cur->next = head1->next;//对当前节点头插
		head1->next = cur;
	}
	if (p != NULL) {//若p未到链表尾，将p剩余元素头插接入链表
		while (p != NULL) {
			List cur = p;
			p = p->next;
			cur->next = head1->next;
			head1->next = cur;
			
		}
	}
	if (q != NULL) {//若q未到链表尾，将q剩余元素头插接入链表
		while (q != NULL) {
			List cur = q;
			q = q->next;
			cur->next = head1->next;
			head1->next = cur;
			
		}
	}
}


int main() { 
	build();
	merge(head1, head2);
	print(head1);
}