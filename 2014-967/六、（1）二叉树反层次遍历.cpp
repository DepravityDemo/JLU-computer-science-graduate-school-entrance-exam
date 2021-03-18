#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

typedef struct Tree {
	int data;
	Tree *left;
	Tree *right;
}*tree;

string qx = "12485309";
string zx = "84251039";

tree build(string qx, string zx) {//前中序构建二叉树
	if (qx.size() == 0)return NULL;
	tree root = (tree)malloc(sizeof(Tree));
	root->data = qx[0] - '0';
	int pos = zx.find(qx[0]);
	root->left = build(qx.substr(1, pos), zx.substr(0, pos));
	root->right = build(qx.substr(pos + 1), zx.substr(pos + 1));
	return root;
}

void relevel(tree root) {//自下而上自右向左层次遍历（就是层次遍历逆序）
	queue<tree>q;
	stack<int>ans;//借助栈实现逆序
	q.push(root);//根节点入队
	while (!q.empty()) {
		tree cur = q.front();
		ans.push(cur->data);//遍历到当前节点入栈
		q.pop();
		if (cur->left != NULL) {//左子树如存在入队
			q.push(cur->left);
		}
		if (cur->right != NULL) {//右子树如存在入队
			q.push(cur->right);
		}
	}
	while (!ans.empty()) {//输出栈中元素即为答案
		printf("%d ",ans.top());
		ans.pop();
	}
}



int main() {
	tree root = build(qx, zx);//树构建过程
	relevel(root);
}