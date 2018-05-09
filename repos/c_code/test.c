#include <stdio.h>

int main(){
    printf("%d\n", NULL);
    printf("%d\n", null);
    printf("%d\n", EOF);
//    printf("%d\n", eof);
    int a = 1;
//    int const a = 1;
    a =2;
    printf("%d\n", a);
    int x = 5;
    int const * j;
    j = &x;
    printf("%d\n", *j);
    return 0;
}
