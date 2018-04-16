#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int n;
		scanf("%d", &n);
		int even = 0, odd = 0;
		for (int i = 0; i < n; i++) {
			int v;
			scanf("%d", &v);
			if (v % 2 == 1) odd += v;
			else even += v;
		}
			printf("%d %d\n", odd, even);
	}
}