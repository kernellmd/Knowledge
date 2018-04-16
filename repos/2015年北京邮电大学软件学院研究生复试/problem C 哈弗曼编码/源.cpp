#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int> > minheap;

int main() {
	char arr[102401];
	int len;
	for (len = 0; (arr[len] = getchar()) != EOF; len++);
	int freq[127] = { 0 };
	for (int i = 0; i < len; i++) {
		freq[arr[i]] ++;
	}
	while (!minheap.empty()) minheap.pop();
	for (int i = 0; i < 127; i++) {
		if (freq[i] != 0) minheap.push(freq[i]);
	}
	int ans = 0;
	while (minheap.size() > 1)
	{
		int a = minheap.top();
		minheap.pop();
		int b = minheap.top();
		minheap.pop();
		ans = ans + a + b;
		minheap.push(a + b);
	}
	printf("%d", ans);
}