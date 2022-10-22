# include <stdio.h>
# include <stdlib.h>

struct student {
    char *name;
};

struct student *creatdStd(){
    return(struct student *)malloc(sizeof(struct student)*10);
}

int main(){
    struct student *A = creatdStd();

    printf("%s\n", A->name);

    return 0;
}