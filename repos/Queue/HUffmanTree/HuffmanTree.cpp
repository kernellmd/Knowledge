#include <queue>
#include <stdio.h>
#include <functional>

using namespace std;

priority_queue <int, vector<int>, greater<int> > Q;
//建立一个小顶堆
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		while (Q.empty() == false) Q.pop(); 
		//清空堆中元素
		for (int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			Q.push(x);
			//将权值放入堆中
		}
		int ans = 0;
		//保存答案
		while (Q.size() > 1) {
			int a = Q.top();
			Q.pop();
			int b = Q.top();
			Q.pop();

			ans += a + b;
			Q.push(a + b);
		}
		printf("%d\n", ans);
	}
	return 0;
}