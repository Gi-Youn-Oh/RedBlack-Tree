#include <stdio.h>

int main(){
    int a;
    printf("%d \n", a); // 임의의 a값
    scanf("%d", &a); // 입력받기 주소값에대해서 
    printf("%d \n", a); // a주소값에 대입해서 변경

    return 0;
}