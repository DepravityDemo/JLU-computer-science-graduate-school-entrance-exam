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
	int a[n] = { 4,7,2,5,8,6,9,2,11,3 };
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
void del(List head,int x) {
	List p = head;
	while (p!= NULL&&p->next!=NULL) {//未到表尾，则循环，因遍历整个链表，所以可以删除所有值为x的节点
		if (p->next->data == x) {//若当前节点下一节点数值等于x，则删除
			List s = p->next;
			p->next = p->next->next;
			free(s);//释放节点
		}
		p = p->next;//指针后移
	}
	return;//删除完成，返回
}
int main() {
	build();
	print(head);
	printf("\n");
	int x;
	while (scanf("%d", &x) != EOF) {
		del(head, x);
		printf("\n");
		print(head);
	}
	
}
