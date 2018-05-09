//测试操作系统总共可以给程序分配多少内存
#include <stdio.h>
#include <stdlib.h>

int main(){
    int count = 0;
    void *p;
    //一次申请100M空间
    while((p = malloc(100 * 1024 * 1024))){
        count ++;
    }
    printf("the sum of memery malloced: %d00M", count);

    return 0;
}
