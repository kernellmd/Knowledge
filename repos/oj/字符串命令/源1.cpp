#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main() {
	char str[101];
	while (scanf("%s", str) != EOF) {
		string strobj(str);
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			char buf[103];
			scanf("%s", buf);

			int flag = buf[0] - '0';
			int begin = buf[1] - '0';
			int len = buf[2] - '0';
			int end = begin + len - 1;

			switch (flag)
			{
			case 0: {
				for (int j = begin; j < end; 
					 j++, end--) {
					char tmp = strobj[j];
					strobj[j] = strobj[end];
					strobj[end] = tmp;
				}
				cout << strobj << endl;
				break;
			}
			case 1: {
				string sub;
				sub.assign(buf, 3, string::npos);
				/*basic_string& assign( const basic_string& str,
				size_type pos,size_type count );
				以 str 的子串 [pos, pos+count) 替换内容。
				若请求的子串越过 string 尾，或若 count == npos ，
				则产生的子串是 [pos, str.size()（就是到字符串的最后）) 。*/
				strobj.replace(begin, len, sub);
				/*basic_string& replace( size_type pos, size_type count,
				const basic_string& str );*/
				cout << strobj << endl;
				break;
			}
			}
		}
	}
	return 0;
}