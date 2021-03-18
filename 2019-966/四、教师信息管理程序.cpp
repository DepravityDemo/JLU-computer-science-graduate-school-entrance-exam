#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;


typedef struct Teacher{//结构体定义
	int num;
	int sex;
	char name[20];
	int year;
	Teacher *next;
}*tea;

void insert(tea head) {//插入过程//按序插入
	tea p= (tea)malloc(sizeof(Teacher));//新建节点
	printf("Please input the number ,sex,name and year:");//读入数据
	scanf("%d %d %s %d", &p->num, &p->sex, p->name, &p->year);
	tea q = head->next;
	while (q->next->num < p->num&&q->next !=NULL) {//查找插入位置
		q = q->next;
	}
	p->next = q->next;//接入链表
	q->next = p;
}

void build(tea head) {//文件中读入并建立链表
	FILE *fp = fopen("input.txt", "r");//打开文件
	tea q = head;
	if (fp == NULL) {//判断打开状态
		printf("FILE OPEN ERROR\n");
	}
	while (!feof(fp)) {
		tea p = (tea)malloc(sizeof(Teacher));//新建节点
		fscanf(fp,"%d %d %s %d", &p->num, &p->sex, p->name, &p->year);//读入数据
		q->next = p;//接入链表
		q = p;
	}
	q->next = NULL;//建立链表尾
}

void sort(tea head) {//排序过程
	tea p = head->next;//冒泡排序指针
	while (p != NULL) {
		tea q = p->next;
		while (q != NULL) {
			if (p->num > q->num) {//当前节点比后面的节点数值大，调换位置
				Teacher tmp = *p;//调换全部内容
				*p = *q;
				*q = tmp;
				tea tmpnext = q->next;//调换next域
				q->next = p->next;
				p->next = tmpnext;
			}
			q = q->next;//指针后移
		}
		p = p->next;//指针后移
	}
}
void del(tea head) {
	printf("Please input the number you want to delete:");//读入要删除节点序号
	int n;
	scanf("%d", &n);
	tea p = head;//遍历指针
	while (p->next != NULL) {
		if (n== p->next->num) {//如果节点匹配则删除该节点
			p->next = p->next->next;
			return;
		}
		p = p->next;
	}
	return;
}
void print(tea head) {//链表输出
	tea p = head->next;
	while (p != NULL) {
		printf("%d %d %s %d\n", p->num, p->sex, p->name, p->year);
		p = p->next;
	}
	printf("\n");
}
int main() {//主程序
	tea head = (tea)malloc(sizeof(Teacher));
	head->next = NULL;
	build(head);//文件建立函数
	print(head);
	sort(head);//排序函数
	print(head);
	insert(head);//插入新元素函数;
	print(head);
	del(head);//删除指定元素
	print(head);
}