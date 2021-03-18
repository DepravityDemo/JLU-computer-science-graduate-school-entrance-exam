#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

typedef struct Node {
	int data;
	Node*next;
}*List;

bool isprime(int n) {
	if (n < 0)n = -n;
	if (n < 2) return false;
	else {
		for (int i = 2; i <= n / 2; i++) {
			if (n%i == 0)return false;
		}
	}
	return true;
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

List sort(List head) {
	List p;//原链表指针
	p = head->next;
	List newhead = (List)malloc(sizeof(Node));//创建新头
	newhead->next = NULL;
	List q,qpre;
	while (p != NULL) {//遍历原链表
		if (isprime(p->data)) {//如果当前节点值绝对值为素数
			p = p->next;//不处理该节点值
			continue;
		}
		else {//节点值不是素数
			q = newhead->next;//q初始化为新头节点下一个节点
			qpre = newhead;//qpre初始为新头节点。
			while (q != NULL && p->data < q->data) {//查找新节点插入位置
				qpre = q;
				q = q->next;
			}
			List tmp= (List)malloc(sizeof(Node));//复制p节点（为不改变原链表结构）
			tmp->data = p->data;
			qpre->next = tmp;//将复制的节点接入新链表
			tmp->next = q;
			p = p->next;
		}
	}
	return newhead;//返回新头
}

int main() {
	build();
	print(head);
	printf("\n");
	List newhead=sort(head);
	print(newhead);
}