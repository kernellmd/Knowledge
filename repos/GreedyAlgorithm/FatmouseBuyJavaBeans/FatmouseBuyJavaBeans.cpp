#include <stdio.h>
#include <algorithm>
using namespace std;

struct goods  //表示可买物品的结构体
{
	double j; //该物品总重
	double f; //该物品总价值
	double s; //该物品性价比
	bool operator < (const goods &A) const {
		//重载小于运算符
		return s > A.s;
	}
};

struct goods buf[1000];

int main() {
	double m;
	int n;
	while (scanf("%lf%d", &m, &n) != EOF) {
		if (m == -1 && n == -1) break;

		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &buf[i].j, &buf[i].f); //输入
			buf[i].s = buf[i].j / buf[i].f; //计算性价比

		}

		sort(buf, buf + n);

		int idx = 0;
        //当前货物下标
		double ans = 0;
		//累加所得的总重量
		while (m > 0 && idx < n) {
			/*
			循环条件为既物品剩余（idx < n），
			还有钱剩余（m > 0）时继续循环
			*/
			if (m > buf[idx].f) {
				ans += buf[idx].j;
				m -= buf[idx].f;

			}
			else {
				ans += buf[idx].j * m / buf[idx].f;
				m = 0;
			}

			idx++;
		}

		printf("%.3lf\n", ans);
	}

	return 0;
}