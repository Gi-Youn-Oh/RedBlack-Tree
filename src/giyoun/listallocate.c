# include <stdio.h>
# include <stdlib.h>

struct student {
    char *name;
};

int main(){
    struct student *A;
    A = (struct student *)malloc(sizeof(struct student)*10);
    struct student A[10]; // 윗줄과 같은의미

    printf("%s\n", A->name);

    return 0;

}