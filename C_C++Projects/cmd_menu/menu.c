#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(){
	char cmd[100];
	while(1){
		scanf("%s", cmd);
		//if(!strcmp(cmd, "help")) 易读性不好
		if(strcmp(cmd, "help") == 0){
			printf("This is help cmd!\n");
		}
		else if(strcmp(cmd, "quit") == 0){
			exit(0);
		}
		else if(strcmp(cmd, "print")){
			printf("This is print cmd!\n");
		}
		else{
			printf("WRONG CMD!\n");
		}
	}

	return 0;
}
