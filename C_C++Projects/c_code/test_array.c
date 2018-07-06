#include <stdio.h>

int main(){
//    int a[10];
//    a[10] = 10;
    printf("here\n");
    
    const int n = 10;
    int b[n];
    for (int i = 0; i < n; i ++) {
        b[i] = i;
    }
    printf("after assign array\n");

    return 0;
}
