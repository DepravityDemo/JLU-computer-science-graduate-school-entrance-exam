#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
using namespace std;

typedef struct Tree {
	int data;
	Tree *left;
	Tree *right;
}*tree; 

bool judge(tree a, tree b) {
	if (!a && !b) {//ab都为空，则对称
		return true;
	}
	else if (!a || !b) {//ab有一个不空则不对称
		return false;
	}
	if (a->data == b->data) {//ab相等，递归a的左子树b的右子树和a的右子树b的左子树
		return judge(a->left, b->right)&&judge( a->right,b->left);
	}
	return false;
}

bool fun(tree root) {//判断函数
	if (!root) {//如果为空树返回true
		return true;
	}
	return judge(root->left, root-> right);//递归判断左右子树
}
string qx = "1234243";
string zx = "3241423";

tree build(string qx, string zx) {//前中序构建二叉树
	if (qx.size() == 0)return NULL;
	tree root = (tree)malloc(sizeof(Tree));
	root->data = qx[0] - '0';
	int pos = zx.find(qx[0]);
	root->left = build(qx.substr(1, pos), zx.substr(0, pos));
	root->right = build(qx.substr(pos + 1), zx.substr(pos + 1));
	return root;
}





int main() {
	tree root = build(qx, zx);//树构建过程
	printf("%d",fun(root));
	
}