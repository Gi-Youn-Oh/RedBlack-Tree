#include <stdio.h>
#include <stdlib.h>

struct NODE { //연결 리스트의 노드 구조체
    struct NODE *next; // 다음 노도의 주소를 저장할 포인터
    int data; // 데이터를 저장할 멤버
};

int main(){
    struct NODE *head = (struct NODE *)malloc(sizeof(struct NODE));

    struct NODE *node1 = (struct NODE *)malloc(sizeof(struct NODE));
    head -> next = node1;
    node1 -> data =10;

    struct NODE *node2 = (struct NODE *)malloc(sizeof(struct NODE));
    node1 -> next = node2;
    node2 -> data =20;

    node2 -> next =NULL;

    struct NODE *curr =head ->next;
    while (curr !=NULL){
        printf("%d\n", curr ->data);
        curr = curr->next;
    }

    free(node2);
    free(node1);
    free(head);

    // 연결리스트에 노드를 추가하는 규칙
    // 1. 노드에 메모리 할당
    // 2. next멤버에 다음 노드의 메모리 주소 저장
    // 3. data 멤버에 데이터 저장
    // 4. 마지막 노드라면 next멤버에 NULL 저장

}