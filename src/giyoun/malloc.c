#include <stdio.h>
#include <stdlib.h>

struct student {
    int a;
    int b;
    char c[10];
};

int main(){
    struct student *ptr = (struct student *)malloc(sizeof(struct student)); // 4바이트 공간을 만들고 시작주소를 할당
    int a = 10.5 ; //10 으로 묵시적 형변환
    double b = 10 ; // 10.0 으로 묵시적 형변환
    ptr -> a =10; // (*ptr).a =10 같은 의미
    printf("sizeof: %lu ptr->a :%d \n",sizeof(struct student), ptr ->a); // 출력
    
    return 0;
}