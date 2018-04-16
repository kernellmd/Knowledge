#include <stdio.h>
#include <algorithm>

using namespace std;

struct program {
	//电视节目结构体
	int startTime;
	//节目开始时间
	int endTime;
	//节目结束时间
	bool operator < (const program &A) const {
		//按照结束时间升序排列
		return endTime < A.endTime;
	}
};

struct program buf[100];

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &buf[i].startTime, 
				          &buf[i].endTime);
		}
		
		sort(buf, buf + n);

		int currentTime = 0, ans = 0;
		//记录当前时间变量的初始值0
		for (int i = 0; i < n; i++) {
			if (currentTime <= buf[i].startTime) {
				currentTime = buf[i].endTime;
				//当前时间变为该节目结束时间
				ans++;

			}
		}

		printf("%d\n", ans); //输出
	}

	return 0;
}