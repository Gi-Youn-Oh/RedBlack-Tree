#include <stdio.h>

int main(){
    FILE* fp = fopen("a.text","w");

    fprintf(fp, "hihi %d\n",5);

    fclose(fp);
    return 0;
}