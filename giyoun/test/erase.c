// // RB-DELETE(T, z)
// //  y = z
// //  y-original-color = y.color
// //  if z.left == T.nil
// //      x = z.right
// //      RB-TRANSPLANT(T, z, z.right)
// //  elseif z.right == T.nil
// //      x = z.left
// //      RB-TRANSPLANT(T, z, z.left)
// //  else y = TREE-MINIMUM(z.right)
// //     y-original-color = y.color
// //     x = y.right
// //     if y.p == z
// //         x.p = y
// //     else RB-TRANSPLANT(T, y, y.right)
// //         y.right = z.right
// //         y.right.p = y
// //     RB-TRANSPLANT(T, z, y)
// //     y.left = z.left
// //     y.left.p = y
// //     y.color = z.color
// //  if y-original-color == BLACK
// //     RB-DELETE-FIXUP(T, x)

// // z 는  트리에서 삭제된 노드 y 는 트리에서 이동한 노드
// // z가 하나이상의 자식을 가질경우 y -> z 가리키도록 설정되며 삭제된다.
// // z가 두개의 자식을 가질 경우 y는 z의 직후 원소로 설정되며 y는 z의 위치로 이동한다.
// rbtree_delete(T,z){
//     node_t* y;
//     y = z;
//     y_original_color = y->color;
//     if (z->left == tree->nil){
//         x = z->right;
//         rbtree_transplant(T,z,z->right);
//     }
//     else if ( z->right == t->nil){
//         x = z->left;
//         rbtree_transplant(T,z,z->left);
//     }
//     else {
//         y = rbtree_minimum(z,right);
//         y_original_color= y->color;
//         x = y->right;
//         if (y->parent == z){
//             x->parent = y;
//         }
//         else
//             rbtree_transplant(T, y, y->right);
//             y->right = z->right;
//             y->right->parent = y;
//         rbtree_transplant(T,z,y);
//         y->left = z->left;
//         y->left->parent = y;
//         y->color = z->color;
//     }
//     if (y_original_color = RBTREE_BLACK){
//         rbtree_delete_fixup(T,x);
//     }
// }

// // z 는  트리에서 삭제될 노드 , y는 z 를 대체할 노드
// // z가 하나 이하의 자식을 가질경우 y -> z 가리키도록 설정되며 삭제된다.
// // z가 두개의 자식을 가질 경우 y는 z의 직후 원소로 설정되며 y는 z의 위치로 이동한다.
// // x는 y의 원래 위치로 이동하는 노드
// int rbtree_erase(rbtree* t,node_t* z){
//     node_t* y; 
//     node_t* x;
//     color_t yOriginalColor; // 원래 컬러 저장하기위해 추후 black 이면 문제가 됨 -> fixup

//     y = z;
//     yOriginalColor = y->color; // y의 색이 변경될 수 있으므로 저장
//     // z의 자식노드가 1개 이하이면
//     if (z->left == t->nil){
//         x = z->right;
//         rbtree_transplant(t,z,z->right);
//     }
//     else if (z->right == t->nil){
//         x = z->left;
//         rbtree_transplant(t,z,z->left);
//     }
//     else{ // z의 자식 노드가 두개일때
//         y = z->right; // y는 z의 오른쪽에 있는 자식노드중 하나이다.
//         while(y->left != t->nil){ // 직후 원소 찾기
//             y = y->left;
//         }
//         yOriginalColor = y->color;
//         x = y->right;

//         if (y->parent == z){ // 만약 y의 부모노드가 z라면
//             x->parent = y; //x의 부모노드는  y 이다.
//         }
//         else {  // y의 부모노드가 z 가 아니라면
//             rbtree_transplant(t,y,y->right); 
//             y->right = z->right;
//             y->right->parent = y;
//         }

//         rbtree_transplant(t, z, y);
//         y->left = z->left;
//         y->left->parent = y;
//         y->color = z->color;
//     } 

//     if (yOriginalColor == RBTREE_BLACK){ // y의 컬러가 원래 블랙이면 문제가 됨
//         rbtree_delete_fixup(t,x); // 재z
//     free(z);
    
//     return 0;
// }