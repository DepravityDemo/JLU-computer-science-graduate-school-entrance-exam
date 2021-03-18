#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
#include<queue>
using namespace std;

typedef struct Tree {
	int data;
	Tree *left;
	Tree *right;
}*tree;


int width(tree root) {//函数主体
	int maxwidth = 0;//储存最大宽度
	queue<tree>q;//储存层次遍历节点
	q.push(root);//根节点入队
	while (!q.empty()) {
		int wid = q.size();//记录当前层节点数目
		if (wid > maxwidth)maxwidth = wid;//与现存最大值比较
		while (wid--) {//当前层所有子节点入队
			tree cur = q.front();
			q.pop();
			if (cur->left != NULL) {
				q.push(cur->left);
			}
			if (cur->right != NULL) {
				q.push(cur->right);
			}
		}
	}
	return maxwidth;//返回最大宽度
}

string qx = "1248530";
string zx = "8425103";

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
	printf("%d\n",width(root));
}