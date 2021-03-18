#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
typedef struct Tree {
	int data;
	Tree *left;
	Tree *right;
}*tree;

string qx = "64215879";
string zx = "12456789";

tree build(string qx, string zx) {//前中序构建二叉树
	if (qx.size() == 0)return NULL;
	tree root = (tree)malloc(sizeof(Tree));
	root->data = qx[0] - '0';
	int pos = zx.find(qx[0]);
	root->left = build(qx.substr(1, pos), zx.substr(0, pos));
	root->right = build(qx.substr(pos + 1), zx.substr(pos + 1));
	return root;
}
void del(tree root,tree father, int x) {//x为查找值，father为父节点
	if (root->data == x) {//找到当前节点
		if (root->left == NULL && root->right == NULL) {//若当前节点左右都为空，直接删除//组节点对应指针置NULL
			if (father->left == root) {
				father->left = NULL;
			}
			else {
				father->right = NULL;
			}
			free(root);
		}
		else if (root->left != NULL&&root->right==NULL) {//有左子树时
			if (father->left = root) {//左子树直接接到father的对应节点
				father->left = root->left;
			}
			else {
				father->right = root->left;
			}
			free(root);
		}
		else if(root->right!=NULL && root->left == NULL){//有右子树时
			if (father->right == root) {//右子树直接接到father的对应节点
				father->right = root->right;
			}
			else {
				father->left = root->right;
			}
			
			free(root);
		}
		else {
			tree p = root->left;//有左右节点
			while (p->right != NULL) {//寻找直接前驱
				p = p->right;
			}
			root->data = p->data;//用直接前驱替换该节点
			free(p);//释放直接前驱
		}
	}
	else {
		if (root->data > x) {//当前节点比x大，往左找
			del(root->left, root, x);
		}
		else {//当前节点比x小，往右找
			del(root->right, root, x);
		}
	}
}


int main() {
	tree root = build(qx, zx);//树构建过程
	del(root, NULL,2);
}