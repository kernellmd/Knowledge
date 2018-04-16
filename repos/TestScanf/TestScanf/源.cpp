#include<stdio.h> 
/*
scanf函数是可以限制输入长度的，但scanf("%s",a)这种写法
没有使用它的限制功能，所以是不检查字符串长度；C/C++也是
不检查数组越界的。防止数组越界的任务完全由程序员事先安排
完成；越界了就会产生不良或危险后果，正规软件中是绝对不能
允许的。正因为“不检查”，当越界操作数组时，在越界部分没有
受到“其他干扰”的情况下自然也能“正常”表现
*/
int main()
{
	char a[5], b[5];
	int i;
	printf("Input the value of a and b:");
	while (scanf("%s%s", a, b) != EOF)
	{
		printf("a=%s,b=%s\n", a, b);
		for (i = 0; i<5; i++)
			printf("%d:(%c) ", a[i], a[i]);
		printf("\n");
		for (i = 0; i<5; i++)
			printf("%d:(%c) ", b[i], b[i]);
		printf("\n");
		printf("Input the value of a and b:");
	}
	return 0;
}