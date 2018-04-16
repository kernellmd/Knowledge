#include <stdio.h>
#include <algorithm>
using namespace std;

int buf[100];

int main() {
	
	int n;
	
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}

		sort(buf, buf + n);
		 
		int target;

		scanf("%d", &target);

		int base = 0, top = n - 1;

		while (base <= top) {
			int mid = (base + top) / 2;
			if (buf[mid] <= target) base = mid + 1;
			else top = mid - 1;
		}

		int ans = top;

		printf("%d", ans);

		printf("\n");
	}

	return 0;
}