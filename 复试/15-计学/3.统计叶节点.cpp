#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
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
int sum = 0;
int preorder(tree root) {//通过改造前序遍历来统计叶节点
	if (root == NULL)return 0;//若当前为节点为空，则没有叶子结点
	if (root->left == NULL && root->right == NULL) {//如果当前节点是叶子节点sum++；
		sum++;
	}
	preorder(root->left);//遍历左子树
	preorder(root->right);//遍历右子树
	return sum;//返回答案
}



int main() {
	tree root = build(qx, zx);//树构建过程
	printf("%d\n", preorder(root));
}