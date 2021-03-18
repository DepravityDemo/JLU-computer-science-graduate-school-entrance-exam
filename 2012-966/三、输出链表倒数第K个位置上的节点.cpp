#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct Node {
	int data;
	Node*next;
}*List;

List head = (List)malloc(sizeof(Node));
int revk(List head,int k) {//函数主体
	List fast;//快指针
	List slow;//慢指针
	fast = slow = head;//快慢指针指向头节点
	for (int i = 0; i < k&&fast!=NULL; i++) {//快指针先走k步
		fast = fast->next;
	}
	if (fast == NULL) {//如果快指针走到NULL了，说明元素不够k个，返回0
		printf("0\n");
		return 0;
	}
	while (fast != NULL) {//快慢指针同时移动，fast到null时，慢指针指向倒数第K个元素
		slow = slow->next;
		fast = fast->next;
	}
	printf("%d", slow->data); return 1;//找到了倒数第K个元素，输出DATA，并返回1
}

void build() {
	List p1 = head;
	const int n = 10;
	int a[n] = { 4,7,2,5,8,6,9,4,11,3 };
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


int main() {

	build();
	print(head);
	printf("\n");
	int k;
	while (scanf("%d", &k) != EOF) {
		if (revk(head, k))printf("YES\n");
		else return printf("NO\n");
	}
	
}