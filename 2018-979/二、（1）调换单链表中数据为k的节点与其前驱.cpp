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
void build() {
	List p1 = head1;
	const int n = 8;
	int a[n] = { 1,3,4,5,0,2,8,7};
	List p;
	for (int i = 0; i < n; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}


int main() {
	build();
	List p = head1->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	int k;
	scanf("%d", &k);//读入要查找节点
	List ppre = head1;//初始化前驱节点指针
	List pprepre = NULL;//初始化前驱的前驱
	p = head1->next;//p后移
	while (p != NULL) {//遍历链表
		if (p->data == k) {//如果p.data==k,则交换p与其前驱
			ppre->next = p->next;
			p->next = ppre;
			pprepre->next = p;
		}
		pprepre = ppre;//更新p前驱的前驱
		ppre = p;//更新p前驱
		p = p->next;//更新p
	}
	p = head1->next;
	while (p != NULL) {
		printf("%d ", p->data);//输出链表
		p = p->next;
	}
}