#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
	int buf[1001];
	int n;
	int depth;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &buf[i]);
		}
		scanf("%d", &depth);

		int begin = (int) pow(2, depth - 1);
		if (begin > n) {
			printf("EMPTY");
		}
		else {
			int end = (int)pow(2, depth) - 1;
			if (end > n) end = n;

			for (int i = begin; i <= end - 1; i++) {
				printf("%d ", buf[i]);
			}
			printf("%d\n", buf[end]);
		}
	}
	return 0;
}