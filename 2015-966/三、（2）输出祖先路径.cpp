#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>.
#include<string.h>
#include<stack>
using namespace std;
typedef struct Tree {
	int data;
	Tree * left;
	Tree *right;
}*tree;

typedef struct jd{
	tree treep;
	int num;
	jd(tree t, int n) :treep(t), num(n) {};
};
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






void count(tree root,int x) {//基本思想，利用非递归后续遍历，当找到节点时，栈中元素即为其祖先。时间复杂度O(n);
	stack<jd>s;//建立栈进行非递归后续遍历
	s.push(jd(root, 0));//根节点入栈
	while (!s.empty()) {//栈飞控循环
		jd c = s.top();//栈顶节点出栈
		s.pop();
		if (c.treep->data == x) {//如果在当前节点
			s.push(jd(c.treep, 0));
			break;
		}
		if (c.num == 0) {//第一次遍历到入栈
			s.push(jd(c.treep, 1));
			if (c.treep->left != NULL) {//若左子树不为空则入栈
				s.push(jd(c.treep->left, 0));
			}
		}
		if (c.num == 1) {
			s.push(jd(c.treep, 2));//第二次遍历到入栈
			if (c.treep->right != NULL) {//若右子树不为空则入栈
				s.push(jd(c.treep->right, 0));
			}
		}
	}
	while (!s.empty()) {//输出栈中元素
		printf("%d ", s.top().treep->data);
		s.pop();
	}
}

int main() {
	tree root = build(qx, zx);//树构建过程
	count(root,8);
}