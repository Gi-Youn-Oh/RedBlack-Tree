#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr = malloc(4); // 4바이트 공간을 만들고 시작주소를 할당
    *ptr = 10; // 주소에 10이라는 data 값을 할당
    printf("%d \n", *ptr); // 출력 
    return 0;
}