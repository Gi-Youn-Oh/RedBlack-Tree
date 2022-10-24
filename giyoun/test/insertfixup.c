// // rbtree_inse
// void rbtree_insert_fixup(rbtree* t,node_t* z){
//     node_t* y;

//     while (z->parent->color = RBTREE_RED){
//         // z의 부모가 조부모의 왼쪽 서브 트리일 경우
//         if (z->parent == z->parent->parent->left){
//             y = z->parent->parent->right; // z 가 삼촌 노드

//             // case1. 노드 z의 삼촌 y가 적색인 경우
//             if (y->color == RBTREE_RED){
//                 z->parent->color == RBTREE_BLACK; // z의 부모노드를 검정으로 변경
//                 y->color == RBTREE_BLACK; // 삼촌 노드도 검정으로 변경
//                 z->parent->parent->color == RBTREE_RED; //조상노드를 레드로 변경
//                 z = z->parent->parent; // 조상 노드에 대해서 상위 노드를 확인해야한다.
            
//             }
//             // case2. z의 삼촌 y가 흑색이며 z가 오른쪽 자식인 경우
//             else { 
//                 if (z == z->parent->right){
//                     z = z->parent; // z를 부모노드의 좌표로 설정
//                     left_rotate(t,z); // 부모노드를 기준으로 좌회전 >> case 3. 경우로 전환
//                 }
//                 // case3. z의 삼촌 y가 흑색이며 z가 왼쪽 자식인 경우
//                 z->parent->color = RBTREE_BLACK; // 부모노드를 검정으로
//                 z->parent->parent->color = RBTREE_RED; // 조상노드를 빨강으로
//                 right_rotate(t,z->parent->parent); // 조상노드를 기준으로 우회전
//             }
//         }
//         // 반대 케이스 기준점 기준으로 뒤집기
//             // z의 부모가 조부모의 왼쪽 서브 트리일 경우    
//         else{
//             y = z->parent->parent->left;

//             //case4. 노드 z의 삼촌 y가 적색인 경우
//             if (y->color == RBTREE_RED) {
//                 z->parent->color = RBTREE_BLACK;
//                 y->color = RBTREE_BLACK;
//                 z->parent->parent->color = RBTREE_RED;
//                 z = z->parent->parent;
//             }
//             // case5. z의 삼촌 y가 흑색이며 z가 왼쪽 자식인 경우
//             else {
//                 if ( z== z->parent->left){
//                     z = z->parent;
//                     right_rotate(t,z);
//                 }
//                 // case 6. z의 삼촌 y가 흑색이며 z가 오르쪽 자식인 경우
//                 z->parent->color = RBTREE_BLACK;
//                 z->parent->parent->color = RBTREE_RED;
//                 left_rotate(t,z->parent->parent);
//             }
//         }
//     }
//     t->root->color = RBTREE_BLACK;    
// }
// // rt_fitup(T,z)

// // while z.p.color == RED
// //     if z.p == z.p.p.left
// //         y = z.p.p.right
// //         if y.color == RED
// //             z.p.color == BLACK //case1
// //             y.color == BLACK //case1
// //             z.p.p.color == RED //case1
// //             z = z.p.p //case1
// //         else if z == z.p.right
// //              z = z.p //case2
// //              Left_Rotate(T,z) //case2
// //             z.p.color = BLACK //case2
// //             z.p.p.color = RED //case2
// //             Right_Rotate(T,z.p.p) //case2 
// //         else
// // T.root.color = BLACK
