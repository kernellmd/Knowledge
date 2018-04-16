#include <stdio.h>
#include <string.h>

struct Node {
	//二叉树结构体
	Node *lchild; //左儿子指针
	Node *rchild; //右儿子指针
	int c; //保存指针
};

struct Node Tree[110]; //静态数组

int Ioc; //静态数组中被使用元素个数
Node *creat() {
	//申请未使用结点
	Tree[Ioc].lchild = Tree[Ioc].rchild = NULL;
	return &Tree[Ioc++];
}

void postOrder(Node *T) { //后序遍历
	if (T->lchild != NULL) {
		postOrder(T->lchild);
	}

	if (T->rchild != NULL) {
		postOrder(T->rchild);

	}

	printf("%d", T->c);
}

void inOrder(Node *T) {
	//中序遍历
	if (T->lchild != NULL) {
		inOrder(T->lchild);

	}

	printf("%d", T->c);

	if (T->rchild != NULL) {
		inOrder(T->rchild);

	}
}

void preOrder(Node *T) {
	//前序遍历
	printf("%d", T->c);
	
	if (T->lchild != NULL) {
		preOrder(T->lchild);
	}

	if (T->rchild != NULL) {
		preOrder(T->rchild);
	}
}

Node *insert(Node *T, int x) {
	//插入数字
	if (T == NULL) { //若当前树为空
		T = creat(); //建立结点
		T->c = x; //数字直接插入其根结点
		return T;
	}
	else if (x < T->c)
		//若x小于根节点值
		T->lchild = insert(T->lchild, x);
	else if (x > T->c)
		//若x大于根节点数值
		T->rchild = insert(T->rchild, x);

	return T;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		Ioc = 0;
		Node *T = NULL;
		//二叉排序树树根结点为空
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			T = insert(T, x);
		}

		preOrder(T);
		printf("\n");
		
		inOrder(T);
		printf("\n");

		postOrder(T);
		printf("\n");
	}
	return 0;
}