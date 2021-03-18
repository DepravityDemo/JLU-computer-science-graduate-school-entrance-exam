#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
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



bool iscomptree(tree root) {
	queue<tree>q;
	q.push(root);
	while (!q.empty()) {
		tree cur = q.front();
		q.pop();
		if (cur == NULL)break;
		q.push(cur->left);
		q.push(cur->right);
	}
	while (!q.empty()) {
		if (q.front() != NULL) {
			return false;
		}
		q.pop();
	}
	return true;
}

int main() {
	tree root = build(qx,zx);
	if (iscomptree(root))return 1;
	else return 0;

}