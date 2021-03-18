#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<iostream>
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

int Width(tree root) {
	queue<tree>q;//储存节点栈
	int widthmax = 0;//储存最大宽度
	q.push(root);//根节点入栈
	while (!q.empty()) {
		int width = q.size();//储存当前宽度
		if (width > widthmax) {//如果当前宽度大于最大宽度，则记录
			widthmax = width;
		}
		while (width--) { //width表示本层节点数，当前层数节点全部遍历完后队列中剩余的即为下一层节点数目
			tree cur = q.front();//当前节点出队访问
			q.pop();
			if (cur->left != NULL) {//若左孩子存在则入队
				q.push(cur->left);
			}
			if (cur->right != NULL) {//若右孩子存在则入队
				q.push(cur->right);
			}
		}
	}
	return widthmax;//返回最大宽度
}



int main() {
	tree root = build(qx, zx);//树构建过程
	printf("%d\n",Width(root));
}