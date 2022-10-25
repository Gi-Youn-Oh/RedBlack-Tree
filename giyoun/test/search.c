// // 이진 트리에서의 서치

// tree_search(x){
//     while( x != nil and k != x->key){
//         if (k < x->key)
//             x = x->left;
//         else 
//             x = x->right;
//     }
//     return x;
// }
// // 트리안의 키값을 찾는다.
// node_t *rbtree_find(const rbtree* t, const key_t key){

//     node_t* current = t->root; // 루트부터 시작해서 찾아내려감

//     while( current != t->nil){ // nil이 아니면 계속 탐색
//         if (current->key == key) // 찾는 키값과 일치하면
//             return current;
        
//         if (current->key < key) // 찾는 키값이 현재 키값보다 크면
//             current = current->right;
//         else                    // 찾는 키값이 현재 키값보다 작으면
//             current = current->left;
//     }
//     return NULL;
// }
