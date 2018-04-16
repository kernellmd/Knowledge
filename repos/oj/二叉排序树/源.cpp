#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct node {
	struct node  *lchild, *rchild;
	int val;
}Node;

Node * insert(Node *T, int x) {
	if (T == NULL) {
		T = (Node*)malloc(sizeof(Node));
		T->lchild = T->rchild = NULL;
		T->val = x;
		return T;
	}
	else if (x < T->val)
	{
		T->lchild = insert(T->lchild, x);
	}
	else if (x > T->val)
	{
		T->rchild = insert(T->rchild, x);
	}
	return T;
}

//前序遍历
void preOrder(Node *T) {
	printf("%d ", T->val);

	if (T->lchild != NULL) {
		preOrder(T->lchild);
	}
	if (T->rchild != NULL) {
		preOrder(T->rchild);
	}
}

//中序遍历
void inOrder(Node *T) {
	if (T->lchild != NULL) {
		inOrder(T->lchild);
	}
	printf("%d ", T->val);
	if (T->rchild != NULL) {
		inOrder(T->rchild);
	}
}

//后序遍历
void postOrder(Node *T) {
	if (T->lchild != NULL) {
		postOrder(T->lchild);
	}
	if (T->rchild != NULL) {
		postOrder(T->rchild);
	}
	printf("%d ", T->val);
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF)
	{
		Node * T = NULL;
		int node;
		scanf("%d", &node);
		Node * root = insert(T, node);
		T = root;
		for (int i = 1; i < n; i++) {
			scanf("%d", &node);
			insert(T, node);
			T = root;
		}
		preOrder(T);
		printf("\n");
		inOrder(T);
		printf("\n");
		postOrder(T);
		printf("\n");
		free(T);
	}
}