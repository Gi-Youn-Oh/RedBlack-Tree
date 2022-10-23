#include <stdio.h>

int main() {
    int a[10] = {1,2,};
    char b[10] = {1,2, };
    printf("a : %p\n",a);
    printf("a : %p\n",a+1);
    printf("a : %p\n",a+2);
    printf("a[0] : %d\n",a[0]);
    printf("a[0] : %d\n",*a);
    printf("a[0] : %d\n",*(a));
    printf("a[0] : %d\n",*(a+0));
    printf("a[1] : %d\n",a[1]);
    printf("a[1] : %d\n",*(a+1));

    printf("b : %p\n",b);
    printf("b+1 : %p\n",b+1);
    printf("b+2 : %p\n",b+2);

    return 0;
    }