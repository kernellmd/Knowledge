#include <cstdio>
using namespace std;

int main() {
	int n;
	while (n--) {
		char str[201];
		gets_s(str, 201);
		char tmp[100];
		int count = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] != ' ') tmp[count++] = str[i];
		}
		int flag[100] = {0};
		for (int i = 5; i < count; i++) {
			if (tmp[i - 1] == '1' && tmp[i - 2] == '1' && 
				tmp[i - 3] == '1' && tmp[i - 4] == '1' && 
				tmp[i - 5] == '1') flag[i] = 1;
		}
		char before_hdlc[100];
		int count_before = 0;
		for (int i = 0; i < count; i++) {
			if (flag[i] != 1) before_hdlc[co; unt++] = tmp[i];
		}
		before_hdlc[count] = '\0';
		puts(before_hdlc);
	}
}