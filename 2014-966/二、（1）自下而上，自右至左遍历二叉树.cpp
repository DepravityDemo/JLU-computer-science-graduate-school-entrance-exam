#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

typedef struct Tree {//二叉树储存结构
	int data;
	Tree *left;
	Tree *right;
}*tree;

string qx = "1243567";
string zx = "2413657";

tree build(string qx, string zx) {//前中序构建二叉树
	if (qx.size() == 0)return NULL;
	tree root = (tree)malloc(sizeof(Tree));
	root->data = qx[0] - '0';
	int pos = zx.find(qx[0]);
	root->left = build(qx.substr(1, pos), zx.substr(0, pos));
	root->right = build(qx.substr(pos + 1), zx.substr(pos + 1));
	return root;
}

void revlevel(tree root) {//函数主体 本题相当于反序层次遍历，层次遍历输出时入栈，再输出栈中元素即可
	queue<tree>q;//建立队列q
	stack<int>s;//建立栈s
	q.push(root);//根节点入队
	while (!q.empty()) {//q非空时循环
		tree cur = q.front();//取队头节点
		s.push(cur->data);//入栈
		q.pop();
		if (cur->left != NULL) {//左子树不为空入队
			q.push(cur->left);
		}
		if (cur->right != NULL) {//右子树不为空入队
			q.push(cur->right);
		}
	}
	while (!s.empty()) {//输出栈中元素
		printf("%d ", s.top());
		s.pop();
	}
}



int main() {
	tree root = build(qx, zx);//树构建过程
	revlevel(root);
}