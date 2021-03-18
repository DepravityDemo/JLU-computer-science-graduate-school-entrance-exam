#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
typedef struct Node//结构体定义
{
	char data;
	Node *next;
}*List ;
List head = (List)malloc(sizeof(Node));//定义头结点

void build() {//测试链表建立
	List p1 = head;
	const int n = 10;
	char a[n] = { 'h','e','l','l','o' };
	List p;
	for (int i = 0; i < n; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}


bool cmp(char str[], List head) {//函数主体
	List p = head->next;//p指向第一个数据节点
	List pos=p;
		for (int i = 0; i < strlen(str)&&p!=NULL;) {//循环比较
			if (str[i] == p->data) {//如果当前str[i]与p.data相等
				i++; p = p->next;//i+1，p指向下一个节点
			}
			else {//不相等则从头开始比较，p指向下一节点
				i = 0;
				pos = pos->next;//当前节点无法匹配，pos后移
				p = pos;//p从当前节点开始
			}
			if (i == strlen(str)) {//str中元素匹配完毕，返回
				return true;
			}
		}

	return false;//到链表尾也未匹配成功返回失败
}


int main() {
	build();
	char str[100];
	while (scanf("%s", str) != EOF) {
		if (cmp(str, head))printf("YES\n");
		else {
			printf("NO\n");
		}
	}
}