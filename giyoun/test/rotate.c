// // // Left rotate
// // Left_Rotate(T,x)
// // y = x.right // y를 설정한다.
// // x.right = y.left // y의 왼쪽 서브 트리를 x의 오른쪽 서브 트리로 옮긴다.
// // if y.left != T.nil
// //     y.left.p = x
// // y.p = x.p    // x의 부모를 y로 연결한다.
// // if x.p == T.nil
// //     T.root = y
// // elseif x == x.p.left
// //     x.p.left = y
// // else x,p.right = y
// // y.left = x  // x를 y의 왼쪽으로 놓는다.
// // x.p = y

// void left_rotate(rbtree* tree, node_t* x){
//     node_t* y;

//     y = x->right;
//     x->right =  y->left;
    
//     if (y->left != tree->nil) // 값이 있으면
//         y->left->parent = x;  
    
//     y->parent = x->parent; // y의 부모주소 (회전 이전 x)에 x의 부모주소  y 를 둔다.

//     if (x->parent == tree->nil) // 부모노드가 없으면 루트노드이다.
//         tree->root = y;
//     else if (x == x->parent->left)
//         x->parent->left = y;
//     else 
//         x->parent->right = y;

//     y->left = x;
//     x->parent = y;

// }

// void right_rotate(rbtree * tree, node_t * x){
//     // TODO!

//     node_t *y;

//     // 1. target의 left으로 y 설정
//     y = x->left;
//     // 2. y의 오른쪽 서브트리를 target의 왼쪽 서브트리로 옮김
//     x->left = y->right;
//     // 3. y의 오른쪽 노드가 NIL이 아니라면, y의 오른쪽 노드 부모를 target으로 설정
//     if (y->right != tree->nil) {
//         y->right->parent = x;
//     }
//     // 4. y의 부모 노드를 target의 부모 노드로 설정
//     y->parent = x->parent;
//     // 5. target의 부모 노드가 nil이라면, 트리 구조체의 root를 y로 설정
//     if (x->parent == tree->nil)
//         tree->root = y;
//     // 6. target이 target 부모 노드의 왼쪽이면, target 부모의 왼쪽을 y로 설정
//     else if (x == x->parent->left)
//         x->parent->left = y;
//     // 7. target이 target 부모 노드의 오른쪽이면, target 부모의 오른쪽을 y로 설정
//     else
//         x->parent->right = y;
//     // 8. target을 y의 오른쪽으로 설정
//     y->right = x;
//     // 9. target의 부모를 y로 설정
//     x->parent = y;
// }
