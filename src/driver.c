#include "rbtree.h"
#include <stdio.h>
int main(int argc, char *argv[]) {
    rbtree *t = new_rbtree();
    rbtree_insert(t, 50);
    rbtree_insert(t, 60);
    rbtree_insert(t, 70);
    node_t *ret1 = rbtree_find(t, 50);
    node_t *ret2 = rbtree_find(t, 60);
    node_t *ret3 = rbtree_find(t, 80);
    // node_t *ret = rbtree_find(t, 50);
    printf("%d\n", ret1->key);
    printf("%d\n", ret2->key);
    if (ret3 == NULL) printf("ret3 is NULL");
}
