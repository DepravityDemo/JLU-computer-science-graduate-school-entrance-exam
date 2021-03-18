#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stack>
using namespace std;
typedef struct Tree {
	int data;
	Tree *left;
	Tree *right;
}*tree;

tree build(char * str) {//本题使用栈结构来代替递归
	int i = 0;
	int len = strlen(str);
	stack<tree>s;
	while (i < len) {
		if (str[i] == '0') {//0时是叶子结点，创建并左右子树置空，入栈
			tree p = (tree)malloc(sizeof(Tree));
			p->left = NULL;
			p->right = NULL;
			s.push(p);
		
		}
		else if (str[i] == '1') {//1时是有左孩子，创建并链接左子树与栈顶元素，右子树置空，入栈
			tree p = (tree)malloc(sizeof(Tree));
			p->left = s.top();
			s.pop();
			p->right = NULL;
			s.push(p);
		}
		else if (str[i] == '2') {//2时是有左孩子，创建并链接左子树右子树与栈顶元素，入栈
			tree p = (tree)malloc(sizeof(Tree));
			p->left = s.top();
			s.pop();
			p->right = s.top();
			s.pop();
			s.push(p);
		}
		i++;
	}
	return s.top();//字符串遍历完后，栈顶元素即为根节点，返回
}

void rev(char str[]) {
	reverse(str, str + strlen(str));//逆转字符串
}


int main() {
	char str[100];
	while (scanf("%s", str) != EOF) {
		rev(str);
		build(str);
	}
}