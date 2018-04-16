#include <stdio.h>
#include <stack>

using namespace std;

stack<int> S; //定义一个堆栈
char str[110]; //保存输入字符串
char ans[110]; //保存输出字符串

int main() {
	while (scanf("%s", str) != EOF) {
		//输入字符串
		int i;
		for (i = 0; str[i] != 0; i++) {
			if (str[i] == '(') {
				//若遇到左括号
				S.push(i);
				//将其数组下标放入堆栈中
				ans[i] = ' ';
				//将对应的输出字符串位置改为空格

			}
			else if (str[i] == ')') {
				//若遇到右括号
				if (S.empty() == false) {
					S.pop();
					ans[i] = ' ';
					//输出中该位置为空格
				}
				else ans[i] = '?';
				/*
				若堆栈为空，则无法找到左括号与其匹配,
				修改输出位置为？
				*/
			}
			else ans[i] = ' ';

		}
		while (!S.empty()) {
			ans[S.top()] = '$';
			S.pop();
		} //while
		ans[i] = 0;
		puts(str);
		puts(ans);
	} //while
	return 0;
} //main