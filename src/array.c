// // 중위순회
// void subtree_to_array(const rbtree* t, key_t* arr, const size_t n, node_t* current, int* i){
//     if (current == t->nil)
//         return;

//     subtree_to_array(t, arr, n, current->left, i);
//     if (*i < n){
//     arr[*(i)] = current->key;
//         i++;
//     }
//     else
//         return;
//     subtree_to_array(t, arr, n, current->right, i);
// }

// int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
//   // TODO: implement to_array
//     if (t->root == t->nil )
//         return;
//     int i = 0;
//     subtree_to_array(t, arr, n, t->root, &i);
//   return 0;
// }
