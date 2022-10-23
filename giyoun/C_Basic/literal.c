# include <stdio.h>
# include <stdlib.h>

// 리터럴도 동적할당과 유사한 감이 있지만 동적할당은 아니다.

struct student {
    char *name;
};

int main(){
    struct student A;
    A.name = "giyoun"; // 리터럴
    printf("%s\n",A.name);

    return 0;

}