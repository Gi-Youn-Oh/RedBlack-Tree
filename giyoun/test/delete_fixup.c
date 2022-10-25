//  while x != T.root and x.color == BLACK
//      if x == x.p.left
//          w = x.p.right
//          if w.color == RED
//              w.color = BLACK // case 1
//              x.p.color . RED // case 1
//              LEFT-ROTATE(T, x.p) // case 1
//              w = x.p.right // case 1
//          if w.left.color == BLACK and w.right.color == BLACK
//             w .color = RED // case 2
//             x = x.p // case 2
//         else if w.right.color == BLACK
//                 w.left.color = BLACK // case 3
//                 w.color = RED // case 3
//                 RIGHT-ROTATE(T, w) // case 3
//                 w = x.p.right // case 3
//             w.color = x.p.color // case 4
//             x.p.color = BLACK // case 4
//             w.right.color = BLACK // case 4
//             LEFT-ROTATE(T, x.p) // case 4
//             x = T.root // case 4
//     else (same thing for the opossite direction “right” and “left” exchanged) // case 5 ~ 8
//  x.color = BLACK

// // 이때의 x는 삭제된 색의 위치(y)를 대체할 노드
//  void rbtree_delete_fixup(rbtree* t,node_t* x){
//     // x가 루트가 아니며, x의 컬러가 블랙일때 반복 
//     while (x !=tree->root && x->color == RBTREE_BLACK){
//         // case 1~4: 부모노드의 왼쪽 서브트리에 있을때
//         if (x == x->parent->left){ 
//             node_t* w = x->parent->right; //x의 형제노드 w

//             // case1. x의 형제 노드 w가 적색일때
//             if (w->color == RBTREE_RED){
//                 w->color = RBTREE_BLACK; // w를 블랙으로 바꾸고
//                 x->parent->color = RBTREE_RED; // 부모노드를 레드로 바꿈
//                 rbtree_leftrotate(T, x->parent); // 부모노드 기준으로 좌회전
//                 w = x->parent->right; // 이동한 x에 대해 형제노드 다시 정의 -> case 2,3,4 로 해결
//             }
//             // case2. x의 형제노드 w가  흑색이며, w의 두 자식 노드가 모두 흑색인 경우
//             if (w->left->color == RBTREE_BLACK && w->right->color == RBTREE_BLACK){
//                 w->color = RBTREE_RED; // 형제노드 w의 색을 레드로 바꾸고(x-extrablack&  w에서  추출> w->red)
//                 x = x ->parent; // x의 부모위치를 새로운 x로 설정
//             } // 새로운x가 rea and black 이면 black 으로 아니면 case 1.2.3.4 생각
//             // case3. x의 형제노드w가 흑색이며, w의 왼쪽 노드가 레드, 오른쪽 노드가 흑색일때
//             else if (w->right->color == RBTREE_BLACK){
//                 w->left->color = RBTREE_BLACK; // w의 왼쪽 노드를 블랙으로
//                 w->color = RBTREE_RED; // w를 레드로
//                 rbtree_rightrotate(T,w); // w를 기준으로 우회전
//                 w = x->parent->right; // w를  새로운  위치로 조정 - > case4 
//             // case4. x의 형제 노드가 흑색이며, w의 오른쪽 자식 노드가 red일때   
//             w->color = x->parent->color; // w의 컬러를 부모노드와 바꿈
//             x->parent->color = RBTREE_BLACK; // 부모노드를 블랙으로
//             w->right->color = RBTREE_BLACK; // 형제노드w의 오른쪽 노드도 블랙으로
//             rbtree_leftrotate(T,x->parent); // 부모노드를 기준으로 좌회전
//             x = tree-> root; // x를 부모노드 루트로 재설정
//             }
//         }
//         // case 5~8 right case / case1~4의 반대 경우
//         else {
//             node_t *w = x->parent->left;

//             // case 5. x의 형제 w가 적색인 경우
//             if (w->color == RBTREEE_RED){
//                 w->color = RBTREE_BLACK;
//                 x->parent->color = RBTREE_RED;
//                 rbtree_rightrotate(T,x->parent);
//                 w = x->parent->left;
//             } 
//             // case 6.
//             if (w->right->color == RBTREE_BLACK && w->left->color == RBTREE_BLACK){
//                 w->color = RBTREE_RED;
//                 x = x->parent;
//             }
//             // case 7.
//             else if (w->left->color == RBTREE_BLACK){
//                 w->right->color = RBTREE_BLACK;
//                 w->color = RBTREE_RED;
//                 rbtree_leftrotate(T,w);
//                 w = x->parent->left;
//             // case8.
//             w->color = x->parent->color;
//             x->parent->color = RBTREE_BLACK;
//             w->left->color =RBTREE_BLACK;
//             rbtree_rightrotate(T,x->parent);
//             x = tree->root;
//             }
//         }
//     } 
//     x->color =RBTREE_BLACK; // 부모노드를 블랙으로
//  }