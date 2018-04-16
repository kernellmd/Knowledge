#include <stdio.h>
int array[101];
int T, N, i, x, max, count;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (i = 0; i<N; i++) {
			scanf("%d", &array[i]);
		}
		x = array[1] - array[0];//开始的等差 
		max = 1;
		count = 1;
		for (i = 1; i<N; i++) {
			if (array[i] - array[i - 1] == x) {
				count++;
			}
			else {
				if (count>max) {
					max = count;
				}
				count = 2;
				x = array[i] - array[i - 1];
			}
		}

		if (count>max) max = count;
		printf("%d\n", max);
	}
	return 0;
}