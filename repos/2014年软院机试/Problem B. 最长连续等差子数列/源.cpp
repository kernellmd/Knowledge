#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int t;
	while (scanf("%d", &t) != EOF) {
		while (t--) {
			int n;
			int buf[101];
			scanf("%d", &n);
			for (int i = 0; i < n; i++) {
				scanf("%d", &buf[i]);
			}
			int pub = buf[1] - buf[0];
			int tmppub = pub;
			int len = 1, tmplen = len;
			for (int i = 1; i < n; i++) {
				tmppub = buf[i] - buf[i - 1];
				//printf("%d", tmppub);
				if (tmppub == pub) tmplen++;
				else
				{
					if (tmplen > len) len = tmplen;
					tmplen = 2;
					pub = tmppub;
					//printf("%d", pub);
				}
			}
			len = max(tmplen, len);
			printf("%d\n", len);
		}
	}
}