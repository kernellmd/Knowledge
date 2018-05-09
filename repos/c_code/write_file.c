#include <stdio.h>

int main(){
    FILE *fp = fopen("test.output", "a");
    if (fp) {
        for (int i = 0; i < 5; i ++) {
            fprintf(fp, "%d ", i);
        }
        fprintf(fp, "%d\n", 5);
        fclose(fp);
    }
    else {
        printf("写入文件失败！");
    }

    return 0;
}
