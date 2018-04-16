#include <cstdio>
#include <stack>
#define MAXSIZE 100
using namespace std;

struct Tree {
	int root[MAXSIZE];
	int size;

	void initTree(int size) {
		this->size = size;
		for (int i = 0; i < size; i++) {
			root[i] = -1;
		}
	}

	void findRoot(int node, stack<int> &s) {
		while (root[node] != -1) {
			s.push(node);
			node = root[node];
		}
		s.push(node);
		return;
	}
};
void initStack(stack<int> &stack) {
	while (!stack.empty())
	{
		stack.pop();
	}
	return;
}
int nextElem(stack<int> &stack) {
	int elem = stack.top();
	stack.pop();
	return elem;
}

int main() {
	int t;
	while (scanf("%d", &t) != EOF) {
		while (t--) {
			int n;
			scanf("%d", &n);
			Tree tree;
			tree.initTree(n);
			int u, v;
			for (int i = 0; i < n - 1; i++) {
				scanf("%d%d", &u, &v);
				u--, v--;
				tree.root[v] = u;
			}
			stack<int> stack_u;
			stack<int> stack_v;

			int m;
			scanf("%d", &m);
			while (m--) {
				initStack(stack_u);
				initStack(stack_v);
				int u, v;
				scanf("%d%d", &u, &v);
				u--, v--;
				tree.findRoot(u, stack_u);
				tree.findRoot(v, stack_v);
				int LCA = stack_u.top();
				stack_u.pop();
				stack_v.pop();
				while (!stack_u.empty() && !stack_v.empty()) {
					int root_u = nextElem(stack_u);
					int root_v = nextElem(stack_v);
					if (root_u == root_v) LCA = root_u;
					else break;
				}
				printf("%d\n", LCA + 1);
			}
		}
	}
	return 0;
}