#include <stdio.h>

int main() {
	int matrix[5][5];
	int rotation, num, x, y;

	while (scanf("%d", &matrix[0][0]) != EOF) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (i == 0 && j == 0) continue;
				scanf("%d", &matrix[i][j]);
			}
		}

		scanf("%d%d%d%d", &rotation, &num, &x, &y);
		x--;
		y--;
		if (rotation == 1 && num == 2) {
			//90度，顺时针，翻转4个数
			int tmp = matrix[x][y];
			matrix[x][y] = matrix[x + 1][y];
			matrix[x + 1][y] = matrix[x + 1][y + 1];
			matrix[x + 1][y + 1] = matrix[x][y + 1];
			matrix[x][y + 1] = tmp;
		}
		if (rotation == 1 && num == 3) {
			//90度，顺时针，翻转9个数
			int tmp = matrix[x][y];
			matrix[x][y] = matrix[x + 2][y];
			matrix[x + 2][y] = matrix[x + 2][y + 2];
			matrix[x + 2][y + 2] = matrix[x][y + 2];
			matrix[x][y + 2] = tmp;
			tmp = matrix[x][y + 1];
			matrix[x][y + 1] = matrix[x + 1][y];
			matrix[x + 1][y] = matrix[x + 2][y + 1];
			matrix[x + 2][y + 1] = matrix[x + 1][y + 2];
			matrix[x + 1][y + 2] = tmp;
		}
		if (rotation == 2 && num == 2) {
			//90度，逆时针，翻转4个数
			int tmp = matrix[x][y];
			matrix[x][y] = matrix[x][y + 1];
			matrix[x][y + 1] = matrix[x + 1][y + 1];
			matrix[x + 1][y + 1] = matrix[x + 1][y];
			matrix[x + 1][y] = tmp;
		}
		if (rotation == 2 && num == 3) {
			//90度，逆时针，翻转9个数
			int tmp = matrix[x][y];
			matrix[x][y] = matrix[x][y + 2];
			matrix[x][y + 2] = matrix[x + 2][y + 2];
			matrix[x + 2][y + 2] = matrix[x + 2][y];
			matrix[x + 2][y] = tmp;
			tmp = matrix[x][y + 1];
			matrix[x][y + 1] = matrix[x + 1][y + 2];
			matrix[x + 1][y + 2] = matrix[x + 2][y + 1];
			matrix[x + 2][y + 1] = matrix[x + 1][y];
			matrix[x + 1][y] = tmp;
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4; j++) {
				printf("%d ", matrix[i][j]);
			}
			printf("%d\n", matrix[i][4]);
		}
		//注意去掉最后一个空格，否则会报错
	}
	return 0;
}