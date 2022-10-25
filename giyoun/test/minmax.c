// rbtree_minimum(node_t* x){
//     while (x->left !=  nil){
//         x = x->left;
//     }
//     return x;
// }

// node_t *rbtree_min(const rbtree *t){
//     if (t->root == t->nil){
//         return NULL;
//     }
//     node_t* current = t->root;

//     while (current->left != t->nil){
//         current = current->left;
//     }
//     return current;
// }



// rbtree_maximum(node_t* x){
//     while (x->right != nil){
//         x = x->right;
//     }
//     return x;
// }

// node_t *rbtree_max(const rbtree *t){
//     if (t->root != t->nil){
//         return NULL;
//     }
//     node_t* current = t->root;

//     while (current->right != t->nil){
//         current = current->right;
//     }
//     return current;
// }