#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

typedef struct node{//结构体定义
	int data;
	node *next;
}*List;


List build() {//构建测试链表（答题的时候不用写）
	int a[7] = { 7,4,2,1,5,6,8 };
	List head = (List)malloc(sizeof(node));
	head->data = a[0];
	List p1 = head;
	for (int i = 1; i < 7; i++) {
		List p= (List)malloc(sizeof(node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
	return head;
}

List merge(List h1, List h2) {//归并过程
	List head = (List)malloc(sizeof(node));//建立新头并初始化
	head->data = -999;
	List p = head;//遍历指针
	while (h1 != NULL && h2 != NULL) {
		if (h1->data < h2->data) {//二路归并插入新链表
			p->next = h1;
			p = h1;
			h1 = h1->next;
			
		}
		else {
			p->next = h2;
			p = h2;
			h2 = h2->next;
		}
	}
	if (h1 != NULL) {//h1元素没用完，直接接到表尾
		p->next = h1;
	}
	else if (h2 != NULL) {//h2元素没用完，直接接到表尾
		p->next = h2;
	}
	return head->next;//返回首元素指针
}

List Sort(List r) {//划分过程
	if (r == NULL or r->next == NULL) {//若只有一个元素或空则返回
		return r;
	}
	List slow = r;//慢指针
	List fast = r->next;//快指针
	while (fast != NULL && fast->next != NULL) {//快指针走到NULL时，slow正好在链表中间位置
		slow = slow->next;
		fast = fast->next->next;
	}
	List h1 = Sort(slow->next);//截取后半部分链表进行排序
	slow->next = NULL;//断开链表
	return merge(Sort(r), h1);//前半部分排序后和后半部分排序后链表进行归并
}


int main() {
	List head = build();//测试链表构建
	head=Sort(head);
	List p = head->next;
	while (p != NULL) {//测试数据输出
		printf("%d ", p->data);
		p = p->next;
	}
}