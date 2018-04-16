#include <stdio.h>
#include <string.h>

struct Node { //树结点结构体
	Node *lchild; //左儿子指针
	Node *rchild; //右儿子指针

	char c; //结点字符信息
};

struct Node Tree[50]; //静态内存分配数组
int Ioc; //静态数组中已经分配的结点的个数

Node *creat() { 
	//申请一个结点空间，返回指向其的指针
	Tree[Ioc].lchild = Tree[Ioc].rchild = NULL;
	//初始化左右儿子为空
	return &Tree[Ioc++];
	//返回指针，且Ioc累加
}

char str1[30], str2[30];
//保存前序和中序遍历结果字符串

void postOrder(Node *T) { //后序遍历
	if (T->lchild != NULL) { //若左子树不空
		postOrder(T->lchild);
		//递归遍历其左子树
	}

	if (T->rchild != NULL) { //若右子树不空
		postOrder(T->rchild); //递归遍历其右子树

	}

	printf("%c", T->c); //遍历该结点，输出其字符信息
}

Node *build(int s1, int e1, int s2, int e2) {
	/*
	由字符串的前序遍历和中序遍历还原树，
	并返回其根节点，其中前序遍历结果为
	由str1[s1]到str2[e1]，中序遍历结果
	为str2[s2]到str2[e2]
	*/
	Node * ret = creat(); //为该树根结点申请空间

	ret->c = str1[s1]; //该结点字符为前序遍历中第一个字符

	int rootIdx;

	for (int i = s2; i <= e2; i++) { 
		//查找该根节点字符在中序遍历中的位置
		if (str2[i] == str1[s1]) {
			rootIdx = i;
			break;
		}
	}

	if (rootIdx != s2) {
		//若左子树不为空
		ret->lchild = build(s1 + 1, s1 + (rootIdx - s2),
			s2, rootIdx - 1);
		//递归还原其左子树
	}

	if (rootIdx != e2) {
		ret->rchild = build(s1 + (rootIdx - s2) + 1, 
			                e1, rootIdx + 1, e2);
		//递归还原其右子树
	}

	return ret;
	//返回根节点指针
}//build

int main() {
	while (scanf("%s", str1) != EOF) {
		scanf("%s", str2); //输入
		Ioc = 0; 
		//初始化静态内存空间中已经使用结点的个数为0
		int L1 = strlen(str1);
		int L2 = strlen(str2); 
		//计算两个字符串的长度
		Node *T = build(0, L1 - 1, 0, L2 - 1);
		//还原整棵树，其根节点指针保存在T中

		postOrder(T); //后序遍历
		printf("\n"); //换行输出
	}

	return 0;
}