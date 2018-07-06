#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v;
    scanf("%d", &v);
    int arr[5] = {0};
    int * arr_mal;
    arr_mal = (int*)malloc(v * sizeof(int));
    free(arr_mal);
    return 0;

}
