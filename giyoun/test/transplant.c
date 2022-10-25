// // TRANSPLANT(T, u, v)는 RB-DELETE(T, z) 에서 삭제할 노드 z와 z를 대체할 노드 y(z보다 키 값이 큰 가장 작은 노드)의 연결 관계를 바꿔주는 역할을 한다.

// RB-TRANSPLANT(T, u, v)
//  if u.p == T.nil
//    T.root = v
//  elseif u == u.p.left
//    u.p.left = v
//  else u.p.right = v
//  v.p = u:p

// rbtree_transplant(rbtree* tree, node_t* u, node_t* v){
//     if (u->parent == tree->nul){
//         t->root = v;
//     }
//     else if (u == u->parent->left){
//         u->parent->left = v;
//     }
//     else  
//         u->parent->right =v;
//     v->parent = u->parent ;
// }
// // u 가 원래 노드 v 가 대체 노드 
// // 삭제시 successor 노드 로 대체
// void rbtree_transplant(rbtree* t, node_t* u, node_t* v){
//   if (u->parent == t->nil){ // u가 루트 노드이면 v를 u 자리에
//     t->root = v; // 즉 루트 노드에 v를 대체한다.
//   }
//   // 루트 노드가 아니면 왼쪽 노드이거나 오른쪽 노드 둘중 하나이다.
//   else if (u==u->parent->left){
//     u->parent->left=v;
//   }
//   else {
//     u->parent->right =v ;
//   }
//   v->parent = u->parent;
// }


  
