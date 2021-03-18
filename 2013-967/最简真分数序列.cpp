#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

typedef struct Node{//链表节点
	int fz;//分子
	int fm;//分母
	Node *next;//后一节点指针
}*List;
int gys(int a, int b) {//求最大公约数过程
	if (a%b == 0)return b;
	else return (b, a%b);
}


int main() {
	int n;
	List head = (List)malloc(sizeof(Node));//初始化头结点
	head->fz = 0;//初始化头结点
	head->fm = 1;//初始化头结点
	head->next = NULL;//初始化头结点
	List p, q;//p为新节点指针，q为链表遍历指针
	while (scanf("%d", &n)!=EOF) {//多次循环用，只需执行一次时可删去
		head->next = NULL;//多次循环用，只需执行一次时可删去
		for (int i = 1; i <= n; i++) {//循环遍历分母
			for (int j = 1; j < i; j++) {//循环遍历分子
				p= (List)malloc(sizeof(Node));//申请新节点
				p->fz = j/gys(i,j);//化简分子
				p->fm = i / gys(i, j);//化简分母
				q = head;//q初始化为头指针
				while (q->next != NULL && p->fz*1.0 / p->fm > q->next->fz*1.0 / q->next->fm) {//寻找插入位置
					q = q->next;
				}
				if (q->next !=NULL &&p->fz*1.0 / p->fm == q->next->fz*1.0 / q->next->fm)continue;//重复值跳过
				p->next = q->next;//插入过程
				q->next = p;//插入过程
			}
		}
		p = head->next;
		while (p != NULL) {//遍历链表 输出答案
			printf("%d/%d ", p->fz, p->fm);
			p = p->next;
		}
	}
}