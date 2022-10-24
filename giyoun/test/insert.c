// RB-insert(T,z)

// y = T.nil
// x = T.root
// while x != T.nil
//     y = x;
//     if (z.key < x.key)
//         x = x.left
//     else    
//         x = x.right
// z.p = y
// if (y == T.nil)
//    T.root = z
// else if (z.key < y.key)
//     y.left = z
// else 
//     y.right = z
// z.left = T.nil
// z.color = RED
// RB-insert-fixup(t,z)

// node_t *rbtree_insert(rbtree *t, const key_t key){
    
//     node_t* y = t->nil;
//     node_t* x = t->root;
//     node_t* z = (node_t*)calloc(1, sizeof(node_t));

//     z->key = key;

//     while (x != t->nil){
//         y = x;
//         if (z->key < x->key)
//             x = x->left;
//         else
//             x = x->right;
//     }

//     z->parent = y;

//     if (y == t->nil) 
//         t->root = z;
//     else if (z->key < y->key)
//         y->left = z;
//     else 
//         y->right = z;
    
//     z->left = t->nil;
//     z->right = t->nil;
//     z->color = RBTREE_RED;
//     rbtree_insert_fixup(t,z)
    
//     return z;
// }
