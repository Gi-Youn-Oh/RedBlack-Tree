 while x != T.root and x.color == BLACK
     if x == x.p.left
         w = x.p.right
         if w.color == RED
             w.color = BLACK // case 1
             x.p.color . RED // case 1
             LEFT-ROTATE(T, x.p) // case 1
             w = x.p.right // case 1
         if w.left.color == BLACK and w.right.color == BLACK
            w .color = RED // case 2
            x = x.p // case 2
        else if w.right.color == BLACK
                w.left.color = BLACK // case 3
                w.color = RED // case 3
                RIGHT-ROTATE(T, w) // case 3
                w = x.p.right // case 3
            w.color = x.p.color // case 4
            x.p.color = BLACK // case 4
            w.right.color = BLACK // case 4
            LEFT-ROTATE(T, x.p) // case 4
            x = T.root // case 4
    else (same thing for the opossite direction “right” and “left” exchanged) // case 5 ~ 8
 x.color = BLACK

 delete_fixup(rbtree* t,node_t* z){
    node_t* x;
    while (x !=tree->root and x->color == RBTREE_BLACK){
        if (x == x->parent->left){
            x = x->parent->right;
            if (w->color == RBTREE_RED){
                w->color = RBTREE_BLACK;
                x->parent->color = RBTREE_RED;
                rbtree_leftrotate(T, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == RBTREE_BLACK and w->right->color == RBTREE_BLACK){
                w->color = RBTREE_RED;
                x = x ->parent;
            }
            else if (w->right->color == RBTREE_BLACK){
                w->left->color = RBTREE_BLACK;
                w->color = RBTREE_RED;
                rbtree_rightrotate(T,w);
                w = x->parent->right;
            w->color = x->parent->color;
            x->parent->color = RBTREE_BLACK;
            w->right->color = RBTREE_BLACK;
            rbtree_leftrotate(T,x->parent);
            x = tree-> root;
            }
        }
        else ( )
    } 
    x->color =RBTREE_BLACK;
 }