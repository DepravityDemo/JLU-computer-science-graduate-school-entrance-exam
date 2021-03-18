#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string>
#include<algorithm>
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
void preorder(tree root, int level) {//函数主体
	if (root == NULL) return;//空树直接返回
	printf("data:%d level:%d\n", root->data,level);//输出节点数据及层数
	preorder(root->left, level + 1);//递归遍历左子树
	preorder(root->right, level + 1);//递归遍历右子树
}

int main() {
	tree root=build(qx, zx);
	preorder(root,0);//函数调用
}