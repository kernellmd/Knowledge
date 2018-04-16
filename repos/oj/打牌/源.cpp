#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

int main()
{
	char a[101];
	char b[101];
	char ch;
	int lena, lenb, flag;
	int count[11];


	while (scanf("%s", a) != EOF)
	{
		//接收回车符  
		//ch = getchar();
		//接收出牌  
		scanf("%s", b);
		//ch = getchar();
		//长度  
		lena = strlen(a);
		lenb = strlen(b);
		//初始化  
		memset(count, 0, sizeof(count));
		//遍历手牌  
		for (int i = 0; i < lena; i++)
		{
			count[a[i] - '0'] ++;
		}
		//检测对方出牌  
		switch (lenb)
		{
		case 1:
		case 2:
		case 3:
		case 4:
			flag = 0;
			for (int key = b[0] - '0'; key <= 9; key++)
				//char key = b[0] - '0' + 1
			{
				if (count[key] >= lenb)
				{
					flag = 1;
					break;
				}
			}
			break;
		case 5:
			flag = 0;
			for (int key = b[0] - '0'; key <= 9; key++)
			{
				if (count[key] > 0 && 
					count[key + 1] > 0 && 
					count[key + 2] > 0 && 
					count[key + 3] > 0 && 
					count[key + 4] > 0)
				{
					flag = 1;
					break;
				}
			}
			break;
		}
		//打印输出  
		if (flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}

	}
	return 0;
}