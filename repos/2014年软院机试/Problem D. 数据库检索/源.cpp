int main() {
	char name[MAXSIZE_MEM], sex[MAXSIZE_MEM], birthday[MAXSIZE_MEM];
	char queryStr[MAXSIZE_STR];
	char queryChar[MAXSIZE_STR];
	scanf("%d", &t);
	for (int time = 0; time<t; time++) {
		//initiate
		stu.clear();
		//input
		scanf("%d%d", &n, &m);
		for (int i = 0; i<n; i++) {
			scanf("%s%s%s", name, sex, birthday);
			stu.push_back(Student(name, sex, birthday));
		}

		//debug**
		//      for (int i=0;i<n;i++){
		//          printf("%s %s %s %s %s %s\n",stu[i].name,stu[i].sex,stu[i].birthday,stu[i].year,stu[i].month,stu[i].day);
		//      }
		//*******

		//search
		bool firstCase = true;
		for (int i = 0; i<m; i++) {
			//initiate
			for (int i = 0; i<n; i++) {
				isAns[i] = true;
			}
			//input
			if (firstCase) {//ÎüÊÕ»Ø³µ 
				getchar();
				firstCase = false;
			}
			gets(queryStr);
			query(queryStr);
			//output
			printAns();
		}
	}
	return true;
}