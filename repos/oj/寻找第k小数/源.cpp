#include <stdc++.h>
//#include <bits/stdc++.h>
//#include <stdio.h> 
//#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	int n, k;
	int buf[1000];

	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}
		sort(buf, buf + n);

		scanf("%d", &k);
		int num = 1;
		int tmp1 = buf[0], tmp2 = 0;

		for (int i = 1; i < n && num != k; i++, tmp2++) {
			if (tmp1 != buf[i]) {
				num++;
				tmp1 = buf[i];
			}
		}
		printf("%d", buf[tmp2]);
	}
	return 0;
}