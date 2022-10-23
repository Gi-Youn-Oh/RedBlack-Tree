#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi; //Pointer integer
    pi = (int *)malloc(sizeof(int)); //malloc = 메모리를 할당하라.
    if(pi == NULL)
    {
        printf("동적 메모리 할당에 실패했습니다.\n");
        exit(1);
    }
    *pi =100;
    printf("%d\n", *pi);
    // 동적 메모리 사용한 이후에는 무조건 해당 메모리를 반환한다.
    free(pi);
    return 0;
}