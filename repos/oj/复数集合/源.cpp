#include <queue>
#include <stdio.h>
#include <iostream>
#include <cmath> //hypot调用库
#include <string>
using namespace std;

struct complex
{
	int real;
	int imag;
	double abs;//求模

	complex(int r, int i) {
		real = r;
		imag = i;
		abs = hypot(r, i); //求模
	}

	bool operator< (const complex & rhs) const {
		return this->abs < rhs.abs;
	}
};

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		priority_queue <complex> maxheap;
		string str;
		for (int i = 0; i < n; i++) {
			cin >> str;
			if (str.compare("Pop") == 0) {
				if (maxheap.empty()) {
					cout << "empty" << endl;
				}
				else
				{
					struct complex tmp = maxheap.top();
					cout << tmp.real << '+' << 'i' << tmp.imag << endl;
				    //也可以写成printf("%d+i%d", x, y);
					maxheap.pop();
					cout << "SIZE = " << maxheap.size() << endl;
				}
			}
			else {
				//可以读入数字和字符混合型输入
				int real, imag;
				char i, plus;
				scanf("%d%c%c%d", &real, &i, &plus, &imag);
				//不能以字符串的形式读入，
				//也可以写成scanf("%d+i%d%*c", &x, &y)
				complex tmp(real, imag);
				maxheap.push(tmp);

				cout << "SIZE = " 
					<< maxheap.size() << endl;
			}
		}
	}
	return 0;
}