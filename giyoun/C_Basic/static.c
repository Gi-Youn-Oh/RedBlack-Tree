#include <stdio.h>

//test case1
// static int Number; // static 변수 선언

// int main() {
    
//     printf("%d\n", Number);

//     return 0;
// }

// test case 2 
// // 전역으로 선언한 static 변수는 그 소스파일 내 모든 함수에서 사용 가능
// static int Number; // static 변수 선언

// // void > 리턴값이 없을 때, (void) 받는 값이 없을떄
// void Test1(){
//     Number += 10;
// }

// void Test2(){
//     Number +=20;
// }

// int main(){
//     printf("정적변수 Number의 값: %d\n", Number);
//     Test1();
//     printf("Test1 실행 후 Number의 값: %d\n", Number);
//     Test2();
//     printf("Test2 실행 후 Number의 값: %d\n", Number);

//     return 0;
// }

// // test case3. 지역변수
// void test() {
//     static int Number; //  static 변수를 지역에 선언
//     Number +=10;
// }

// void test2(){
//     Number += 20; // 참조 못함
// }
// int main(){
//     printf("정적변수 Number의 값: %d\n", Number);
//     Test1();
//     printf("Test1 실행 후 Number의 값: %d\n", Number);
//     Test2();
//     printf("Test2 실행 후 Number의 값: %d\n", Number);

//     return 0;
// }

int Test1() {
    static int Number;
    Number++;
    return Number;
}

int main(){

    for (int i = 0; i < 5; i++){
        printf("%d", Test1());
    }
    printf("\n"); // 개행
}