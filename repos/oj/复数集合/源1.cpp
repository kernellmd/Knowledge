

// Author: 代码疯子
// C++优先队列
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <iterator>
using namespace std;

class Node
{
public:
	char str[80];
	int len;
public:
	bool operator<(const Node& rhs) const
	{
		return this->len < rhs.len;
	}
};

int main(int argc, char **argv)
{
	int n, i;
	while (EOF != scanf("%d%*c", &n))
	{
		priority_queue<Node> pqueue;
		char op[100] = { 0 };
		int x, y;
		Node node;
		for (i = 0; i < n; ++i)
		{
			scanf("%s", op);
			if (!strcmp(op, "Pop"))
			{
				if (pqueue.empty())
				{
					printf("empty\n");
				}
				else
				{
					node = pqueue.top();
					pqueue.pop();
					printf("%s\n", node.str);
				}
			}
			else
			{
				scanf("%d+i%d%*c", &x, &y);
				node.len = x * x + y * y;
				sprintf(node.str, "%d+i%d", x, y);
				pqueue.push(node);
				// 题目输出数据格式有误
				// printf("%d\n", pqueue.size());
			}
		}
	}
	return 0;
}