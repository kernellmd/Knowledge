#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	char a[101];   //Ô­×Ö·û´®
	char b[103];   //ÃüÁî×Ö·û´®
	int n;
	while (scanf("%s", &a) != EOF)
	{
		cin >> n;
		for (int i = 0; i<n; i++)
		{
			cin >> b;
			int m = b[0] - '0';      //ÃüÁîÀàĞÍ
			int ans = b[1] - '0';
			int len = b[2] - '0';

			switch (m)
			{
			case 0: {
				char temp;
				for (int j = 0; j <= (len - 1) / 2; j++)
				{
					temp = a[ans + len - 1 - j];
					a[ans + len - 1 - j] = a[ans + j];
					a[ans + j] = temp;
				}
				cout << a << endl;
				break;
			}
			case 1: {
				string aa = a;
				string bb = b;
				string s1 = aa.substr(0, ans);
				string s2 = aa.substr(ans + len, strlen(a) - ans - len);
				string s3 = bb.substr(3, strlen(b) - 3);
				string s4 = s1 + s3 + s2;
				cout << s4 << endl;
				strcpy(a, s4.c_str());
			}
			}


		}
	}
	return 0;

}