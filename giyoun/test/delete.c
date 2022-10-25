// RB-DELETE(T, z)
//  y = z
//  y-original-color = y.color
//  if z.left == T.nil
//      x = z.right
//      RB-TRANSPLANT(T, z, z.right)
//  elseif z.right == T.nil
//      x = z.left
//      RB-TRANSPLANT(T, z, z.left)
//  else y = TREE-MINIMUM(z.right)
//     y-original-color = y.color
//     x = y.right
//     if y.p == z
//         x.p = y
//     else RB-TRANSPLANT(T, y, y.right)
//         y.right = z.right
//         y.right.p = y
//     RB-TRANSPLANT(T, z, y)
//     y.left = z.left
//     y.left.p = y
//     y.color = z.color
//  if y-original-color == BLACK
//     RB-DELETE-FIXUP(T, x)

rbtree_delete(T,z){
    node_t* y;
    y = z;
    y_original_color = y->color;
    if (z->left == tree->nil){
        x = z->right;
        rbtree_transplant(T,z,z->right);
    }
    else if ( z->right == t->nil){
        x = z->right;
        rbtree_transplant(T,z,z->left);
    }
    else {
        y = rbtree_minimum(z,right);
        y_original_color= y->color;
        x = y->right;
        if (y->parent == z){
            x->parent = y;
        }
        else
            rbtree_transplant(T, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        rbtree_transplant(T,z,y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (y_original_color = RBTREE_BLACK){
        rbtree_delete_fixup(T,x);
    }
}