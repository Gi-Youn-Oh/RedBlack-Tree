// // grandparent node
// node_t* grandparent(node_t* n){
//   if ((n != NULL) && (n->parent != NULL))
//     return n-> parent -> parent;
//   else 
//     return NULL;
// }

// node_t* uncle(node_t* n){
//   node_t* g = grandparent(n);
//   if (g == NULL)
//     return NULL; // no grandparent means no uncle
//   if (n->parent == g->left)
//     return g->right;
//   else 
//     return g->left;
// }

// // case 1
// void rbtree_insert_case1(node_t *n){
//   if (n->parent == NULL)
//   n->color =RBTREE_BLACK;
//   else
//   rbtree_insert_case2(n);
// }

// // case 2
// void rbtree_insert_case2(node_t *n){
//   if (n->parent->color = RBTREE_BLACK)
//   return;
//   else
//   rbtree_insert_case3(n);
// }

// // case 3
// void rbtree_insert_case3(node_t *n){
//   node_t *u = uncle(n), *g;

//   if ((u != NULL) && (u->color == RBTREE_RED)){
//     n->parent->color = RBTREE_BLACK;
//     u->color = RBTREE_BLACK;
//     g = grandparent(n);
//     g->color = RBTREE_RED;
//     rbtree_insert_case1(g);
//   }
//   else{
//     rbtree_insert_case4(n);
//   }
// }

// // case 4
// void rbtree_insert_case4(node_t *n){
//   node_t* g = grandparent(n);

//   if((n == n->parent->right) && (n->parent == g-> left)){
//     rotate_left(n->parent);
//     n=n->left;
//   }
//   else if ((n ==n->parent->left) && (n->parent == g->right)){
//    rotate_right(n->parent);
//    n = n->right;
//   }
//   rbtree_insert_case5(n);
// }

// static void rotate_left (node_t* n){
//   node_t* c = n -> right ;
//   node_t* p = n -> parent;
//   if (c -> left != NULL)
//     c-> left -> parent =n;

//   n->right = c->left;
//   n->parent  = c;
//   c->left =n;
//   c->parent = p;

//   if (p != NULL){
//     if (p->left == n)
//       p->left = c; 
//     else 
//       p->right = c;
//   }
// }

// static void rotate_right(node_t* n){
//   node_t* c =n->left;
//   node_t* p =n->parent;

//   if (c->right != NULL)
//     c->right->parent = n;
  
//   n->left = c->right;
//   n->parent  = c;
//   c->right =n;
//   c->parent = p;

//   if (p != NULL){
//     if (p-> right == n)
//       p->right = c;
//     else 
//       p->left =c;
//   }
// }

// // case 5
// void rbtree_insert_case5(node_t* n){
//   node_t *g = grandparent(n);

//   n->parent->color = RBTREE_BLACK;
//   g->color = RBTREE_RED;
//   if (n == n->parent->left)
//     rotate_right(g);
//   else 
//     rotate_left(g);
// }
