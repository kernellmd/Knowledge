#include <cstdio>
using namespace std;


int main() {
	int t;
	while (scanf("%d", &t) != EOF) {
		while (t--) {
			char arr[5][5];
			int n = 0, m = 0;
			scanf("%d%d", &n, &m);
			for (int i = 0; i < m; i++) {
				arr[0][i] = '#';
				arr[n - 1][i] = '#';
				arr[i][0] = '#';
				arr[i][m - 1] = '#';
			}
			for (int i = 1; i < n - 1; i ++ ){
				for (int j = 1; j < m - 1; j++) {
					arr[i][j] = '*';
				}
			}
			for (int i = 0; i < n; i ++ ) {
				for (int j = 0; j < m; j++) {
					printf("%c", arr[i][j]);
				}
				printf("\n");
			}
		}
	}
}