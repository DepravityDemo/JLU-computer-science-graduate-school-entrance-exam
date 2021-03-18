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

int abs(int a) {
	if (a < 0)return -a;
	else return a;
}

string qx = "124875309";
string zx = "784251039";

tree build(string qx, string zx) {//前中序构建二叉树
	if (qx.size() == 0)return NULL;
	tree root = (tree)malloc(sizeof(Tree));
	root->data = qx[0] - '0';
	int pos = zx.find(qx[0]);
	root->left = build(qx.substr(1, pos), zx.substr(0, pos));
	root->right = build(qx.substr(pos + 1), zx.substr(pos + 1));
	return root;
}

int getdeep(tree root) {//获取树深度
	if (root == NULL)return 0;//空间点为0
	else {
		return max(getdeep(root->left), getdeep(root->right)) + 1;//返回左右节点深度最大的+1则是当前节点深度
	}
}


bool isbalance(tree root) {
	if (root == NULL)return true;//空节点也是平衡二叉树
	else {
		if (abs(getdeep(root->right)- getdeep(root->left)) > 1) {//判断左右子树高度差是否超过一
			return false;
		}
	}
	return isbalance(root->left) && isbalance(root->right);//递归判断当前节点左右子树
}

int main() {
	tree root = build(qx, zx);//树构建过程
	if (isbalance(root)) { printf("YES\n"); }
	else {
		printf("NO\n");
	}
}