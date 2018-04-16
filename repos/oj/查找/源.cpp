#include <stdio.h>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int hash[101];
		for (int i = 0; i < 100; i++) {
			hash[i] = 0;
		}
		int vn;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &vn);
			hash[vn] ++;
		}
		int m;
		scanf("%d", &m);
		int vm;
		for (int i = 0; i < m; i++) {
			scanf("%d", &vm);
			if (hash[vm] != 0) printf("YES");
			else printf("NO");
			printf("\n");
		}

	}
}