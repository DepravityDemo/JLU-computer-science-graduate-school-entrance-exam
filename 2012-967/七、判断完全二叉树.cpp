#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

typedef struct Tree {
	int data;
	Tree *left;
	Tree *right;
}*tree;

string qx = "12485309";
string zx = "48251039";//删除8时是完全二叉树

tree build(string qx, string zx) {//前中序构建二叉树
	if (qx.size() == 0)return NULL;
	tree root = (tree)malloc(sizeof(Tree));
	root->data = qx[0] - '0'; 
	int pos = zx.find(qx[0]);
	root->left = build(qx.substr(1, pos), zx.substr(0, pos));
	root->right = build(qx.substr(pos + 1), zx.substr(pos + 1));
	return root;
}

bool isfulltree(tree root) {
	queue<tree>node;//构建层次遍历序列
	node.push(root);//根节点入队
	while (!node.empty()) {
		tree cur = node.front();//当前节点出队
		node.pop();
		if (cur == NULL)break;//如果当前节点为空，不入队左右节点
		node.push(cur->left);//入队左右节点
		node.push(cur->right);
	}
	while (!node.empty()) {//检查队列中剩余元素是否都为空，若cur为空间节点时，队列内都为空，说明为完全二叉树，若队列中还有元素则不是。
		if (node.front())return false;
	}
	return true;
}




int main() {
	tree root = build(qx, zx);//树构建过程
	if (isfulltree(root))return 1;
	else return 0;
}