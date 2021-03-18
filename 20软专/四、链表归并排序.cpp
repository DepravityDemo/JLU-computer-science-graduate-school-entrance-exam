#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

typedef struct Student {
	int xh;
	char name[20];
	int score;
	Student*next;
}*stu;

stu build() {//建立第一个两边
	stu head = (stu)malloc(sizeof(Student));
	int n = 6;
	stu p1 = head;
	while (n--) {
		stu p = (stu)malloc(sizeof(Student));
		scanf("%d %s %d", &p->xh, p->name, &p->score);
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
	return head;
}
stu build2() {
	stu head = (stu)malloc(sizeof(Student));//建立第二个链表
	stu p1 = head;//定义尾插指针
	FILE *fp;//定义文件指针
	fp = fopen("C:\\Users\\93482\\Desktop\\original.txt", "r");//只读打开文件,换成你电脑上的绝对路径或者删除前边的，将文件放入程序同目录
	if (fp == NULL) {//判断文件打开状态
		printf("FILE OPEN ERROR\n");
	}
	while (!feof(fp)) {//未到文件结尾时读取
		stu p = (stu)malloc(sizeof(Student));//建立新节点
		fscanf(fp,"%d %s %d", &p->xh, p->name, &p->score);//赋值数据
		p1->next = p;//尾插加入链表
		p1 = p;
	}
	p1->next = NULL;//添加链表尾
	return head;//返回头结点
}

void sort(stu head) {//排序函数主体
	stu p = head->next;
	stu q;
	while (p != NULL) {//链表冒泡排序过程
		q = p->next;
		while (q != NULL) {
			if (p->score > q->score) {
				Student tmp;//先整体调换
				tmp = *p;
				*p = *q;
				*q = tmp;
				stu tmpnext;
				tmp.next = p->next;//再更改next指针
				p->next = q->next;
				q->next = tmp.next;
			}
			q = q->next;//下一节点
		}
		p = p->next;//下一节点
	}
}

stu merge(stu head1,stu head2) {
	stu p = head1->next;//第一链表指针
	stu q = head2->next;//第二链表指针
	stu newhead = (stu)malloc(sizeof(Student));//建立新头
	newhead->next = NULL;//初始化尾结点
	stu k = newhead;//新链表指针
	while (p != NULL && q != NULL) {
		if (p->score <=q->score) {//p所指元素成绩低，将p接入新链表
			k->next = p;
			k = p;
			p = p->next;
		}
		else { 
			k->next = q;//否则将q接入新链表
			k = q;
			q = q->next;
		}
	}
	if (q != NULL) {//接入未到末尾链表
		k->next = q;
	}
	if (p != NULL) {
		k->next = p;
	}
	return newhead;//返回新头
}

void print(stu head) {
	stu p = head->next;
	while (p != NULL) {
		printf("%d %s %d\n", p->xh, p->name, p->score);
		p = p->next;
	}
}
int main() {
	stu head = build();//建立第一个链表
	stu head2 = build2();//建立第二个链表
	sort(head);//第一个链表排序
	sort(head2);//第二个链表排序
	printf("\n");
	print(head);
	printf("\n");
	print(head2);
	stu newhead=merge(head, head2);//归并
	printf("\n");
	print(newhead);
}