#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

typedef struct Node {
	int data;
	Node* LLink;
	Node* RLink;
	int Freq;
}node,*List;

List head = (List)malloc(sizeof(node));
void build() {//双向链表构建过程
	int a[6] = { 3,4,2,1,5,7 };
	List p, ppre;
	ppre = head;
	for (int i = 0; i < 6; i++) {
		p = (List)malloc(sizeof(node));;
		p->data = a[i];
		p->Freq = 0;
		ppre->RLink = p;
		p->LLink = ppre;
		ppre = p;
	}
	ppre->RLink = NULL;
}

void Locate(int x) {//函数主体
	List p, q;
	p = head->RLink;//P指向头结点下一个节点
	while (p != NULL) {
		if (p->data == x) {//如果p的数据等于x
			p->Freq++;//p频率++
			break;//退出循环
		}
		p = p->RLink;//p指向下一个节点
	}
	if (p->LLink == head)return;//如果p本身就是第一个数据结点不进行处理
	else {
		p->LLink->RLink = p->RLink;//将p从原链表摘下
		if (p->RLink != NULL)p->RLink->LLink = p->LLink;
		q = head->RLink;//寻找p插入位置
		while (q != NULL && q->Freq > p->Freq) {
			q = q->RLink;
		}
		q->LLink->RLink = p;//p插入到q之前
		p->LLink = q->LLink;
		q->LLink = p;
		p->RLink = q;
	}
	
}


void print(List head) {//链表输出函数
	List p = head->RLink;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->RLink;
	}
}
int main() {
	build();
	int x;
	print(head);
	while (scanf("%d", &x) != EOF) {//读入X
		Locate(x);//调用函数
		print(head);//输出链表
	}
}