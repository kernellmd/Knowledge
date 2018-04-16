#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct Student {
	//用于表示学生个体的结构体
	char no[100]; //学号
	char name[100]; //姓名
	int age; //年龄
	char sex[5]; //性别
	bool operator < (const Student & A) const {
		//重载<运算符
		return strcmp(no, A.no) < 0;
	}
};

struct Student buf[1000];

int main(int argc, char** argv) {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%s%s%s%d", &buf[i].no, &buf[i].name,
				&buf[i].sex, &buf[i].age);
		} //读入数据

		sort(buf, buf + n); //对数组排序使其按学号升序排列

		int m;
		scanf("%d", &m); //有m组询问

		while (m-- != 0) { //保证查询次数为m 
			int ans = -1; //目标元素下标，初始化为-1
			char x[30];
			scanf("%s", x); //待查找学号
			int top = n - 1, base = 0;
			//初始时，开始下标0，结束下标n-1，查找子集为整个数组
			while (top >= base) {
				//查找子集不空时重复二分查找
				int mid = (top + base) / 2;
				//计算中间点下标
				int tmp = strcmp(buf[mid].no, x);
				//比较中间点学号与目标学号 
				if (tmp == 0) {
					ans = mid;
					break;
					//若相等，则查找完成，跳出二分查找 
				}
				else if (tmp > 0) top = mid - 1;
				//若大于，则结束下标变为中间点前一个点下标 
				else base = mid + 1;
				//若小于，则开始点下标变为中间点后一个点坐标 

			} //while

			if (ans == -1) {
				printf("No Answer!\n");
			}
			else printf("%s %s %s %d\n", buf[ans].no, buf[ans].name,
				buf[ans].sex, buf[ans].age);
		} //while  
	} //while 
	return 0;
}