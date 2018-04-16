#include <cstdio>
#include <cmath>
using namespace std;

void group(int size, int * arr) {
	if (size > 2) {
		size /= 2;
		int *even = new int[size];
		int *odd = new int[size];
		int count_even = 0;
		int count_odd = 0;
		for (int i = 0; i < size * 2; i++) {
			if (i % 2 == 0) {
				even[count_even++] = arr[i];
			}
			else {
				odd[count_odd++] = arr[i];
			}
		}
		count_even = 0;
		count_odd = 0;
		for (int i = 0; i < size; i++) {
			arr[i] = even[count_even++];
			arr[i + size] = odd[count_odd++];
		}
		delete[] even;
		delete[] odd;
		group(size, arr);
		group(size, arr + size);
	}
	else return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int k;
		scanf("%d", &k);
		int arr[4096];
		int len =(int) pow(2, k);
		for (int i = 0; i < len; i++) {
			scanf("%d", &arr[i]);
		}
		group(len, arr);
		for (int i = 0; i < len; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}