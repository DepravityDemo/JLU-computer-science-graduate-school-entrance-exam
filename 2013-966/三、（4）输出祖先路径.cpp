#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<stack>
using namespace std;

typedef struct Tree {
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

typedef struct jd {//建立后续遍历辅助结构体
	tree treep;
	int num;
	jd(tree t, int i) :treep(t), num(i) {}
};

void find(tree root,int x) {
	stack<jd>mystk;//建立答案栈
	mystk.push(jd(root, 0));//根节点入栈
	while (!mystk.empty()) {//栈飞空时循环
		jd c = mystk.top();//栈顶节点出栈
		mystk.pop();
		if (c.treep->data == x) {//如果当前节点等于要查找节点，当前节点入栈，退出循环
			mystk.push(jd(c.treep, 0));
			break;
		}
		if (c.num == 0) {//第一次遍历到该节点
			mystk.push(jd(c.treep, 1));//入栈，标记1
			if (c.treep->left != NULL) {//如果左子树不空，左子树入栈
				mystk.push(jd(c.treep->left, 0));
			}
		}
		else if (c.num == 1) {//第二次遍历到该节点
			mystk.push(jd(c.treep, 2));//入栈，标记2
			if (c.treep->right != NULL) {//右子树不空，右子树入栈
				mystk.push(jd(c.treep->right, 0));
			}
		}
	}
	while (!mystk.empty()) {//输出栈内元素
		printf("%d ", mystk.top().treep->data);
		mystk.pop();
	}
	
	


}




int main() {
	tree root = build(qx, zx);//树构建过程
	find(root, 7);
}