#include <stdio.h>
#include <algorithm>
using namespace std;

struct couple
{
	int x;
	int y;
	bool operator < (const couple & rhs) const {
		if (x == rhs.x) {
			return y < rhs.y;
		}
		else
		{
			return x < rhs.x;
		}
	}
};

struct couple buf[1000];

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &buf[i].x, &buf[i].y);
		}
		sort(buf, buf + n);
		printf("%d %d\n", buf[0].x, buf[0].y);
	}

	return 0;
}