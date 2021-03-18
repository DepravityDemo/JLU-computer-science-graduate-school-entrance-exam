#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

typedef struct Node {
	int data;
	Node*left;
	Node*right;
}*List;
List head = (List)malloc(sizeof(Node));
void build() {//尾插法构建双向链表
	int a[7] = { 1,2,3,4,5,6,7 };
	List p,q;
	q = head;
	head->right = NULL;
	for (int i = 0; i < 7; i++) {
		List p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p->right = q->right;
		q->right = p;
		p->left = q;
		q = p;
	}
	q->right = head;
	head->left = q;

}

void change(List head) {
	List tail = head->left;//尾结点指针
	int num = 1;//奇偶计数变量
	List p = head->right;//p指向第一个非头节点
	while (p != tail) {
		if (num % 2 == 0) {//偶数时
			List cur=p;//储存当前节点
			p = p->right;//p指向后继
			cur->left->right = p;//当前节点的前驱链接到当前节点后继
			p->left = cur->left;//当前节点后继连接到前驱
			cur->right = tail->right;//将当前节点插入表尾
			tail->right->left = cur;//更新表尾指针下一个节点前驱
			tail->right = cur;//跟新表尾指针后继为当前节点
			cur->left = tail;//当前节点前驱设为尾节点（当前的尾结点只是原链表尾，并未实际意义上的改造后的链表尾）
		}
		else {//奇数时相对位置不变，直接下一个节点
			p = p->right;
		}
		num++;//计数变量++
	}

}

int main() {
	build();
	change(head);
}