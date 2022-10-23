#include <stdio.h>

typedef struct student // 변수의 정의
{
    int num;
    char name[10];
    char phonoe[12]; // 010-xxxx-xxxx 11글자 > 12칸
    int kor;
    int eng;
    int math;
} Student;

// 원래는 int A 로 선언하지만 struct student A 로 정의해야함
// > 불편하기 때문에  type def A B / A를 B로 대체
int main(){
    struct student A; //변수의 선언
    Student A; // 같은 의미
    A.kor = 80;
    A.eng = 70;
    A.math =60;

    printf("%d %d %d\n", A.kor,A.eng,A.math);

    return 0;
}