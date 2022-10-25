#include "rbtree.h"

#include <stdlib.h>

// init
rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
    // TODO: initialize struct if needed
  if (p == NULL)
    return NULL;
  (p -> nil) =  (node_t*)calloc(1, sizeof(rbtree));
  (p-> root) = (p->nil);
  (p-> nil)->color = RBTREE_BLACK;

  return p;
}

// 왼쪽 회전
void left_rotate(rbtree* tree, node_t* x){
    node_t* y;

    y = x->right;
    x->right =  y->left;
    
    if (y->left != tree->nil) // 값이 있으면
        y->left->parent = x;  
    
    y->parent = x->parent; // y의 부모주소 (회전 이전 x)에 x의 부모주소  y 를 둔다.

    if (x->parent == tree->nil) // 부모노드가 없으면 루트노드이다.
        tree->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else 
        x->parent->right = y;

    y->left = x;
    x->parent = y;

}

// 오른쪽 회전
void right_rotate(rbtree * tree, node_t * x){
    // TODO!

    node_t *y;

    // 1. target의 left으로 y 설정
    y = x->left;
    // 2. y의 오른쪽 서브트리를 target의 왼쪽 서브트리로 옮김
    x->left = y->right;
    // 3. y의 오른쪽 노드가 NIL이 아니라면, y의 오른쪽 노드 부모를 target으로 설정
    if (y->right != tree->nil) {
        y->right->parent = x;
    }
    // 4. y의 부모 노드를 target의 부모 노드로 설정
    y->parent = x->parent;
    // 5. target의 부모 노드가 nil이라면, 트리 구조체의 root를 y로 설정
    if (x->parent == tree->nil)
        tree->root = y;
    // 6. target이 target 부모 노드의 왼쪽이면, target 부모의 왼쪽을 y로 설정
    else if (x == x->parent->left)
        x->parent->left = y;
    // 7. target이 target 부모 노드의 오른쪽이면, target 부모의 오른쪽을 y로 설정
    else
        x->parent->right = y;
    // 8. target을 y의 오른쪽으로 설정
    y->right = x;
    // 9. target의 부모를 y로 설정
    x->parent = y;
}

//node 삭제  후위 순회 방식 노드 메모리 반환
void delete_rbtreeNode(rbtree* t, node_t* key){
  if(key->left != t->nil)
    delete_rbtreeNode(t, key -> left);
  if(key->right != t->nil)
    delete_rbtreeNode(t, key -> right);
  free(key);
  key = NULL; 
}
// tree 삭제
void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  if (t->root != t->nil)
    delete_rbtreeNode(t,t->root);
  free(t->nil);
  free(t);
}

// 삽입 후 재조정
void rbtree_insert_fixup(rbtree* t,node_t* z){
    node_t* y;

    while (z->parent->color == RBTREE_RED){
        // z의 부모가 조부모의 왼쪽 서브 트리일 경우
        if (z->parent == z->parent->parent->left){
            y = z->parent->parent->right;

            // case1. 노드 z의 삼촌 y가 적색인 경우
            if (y->color == RBTREE_RED){
                z->parent->color = RBTREE_BLACK;
                y->color = RBTREE_BLACK;
                z->parent->parent->color = RBTREE_RED;
                z = z->parent->parent;
            
            }
            // case2. z의 삼촌 y가 흑색이며 z가 오른쪽 자식인 경우
            else { 
                if (z == z->parent->right){
                    z = z->parent;
                    left_rotate(t,z);
                }
                // case3. z의 삼촌 y가 흑색이며 z가 오른쪽 자식인 경우
                z->parent->color = RBTREE_BLACK;
                z->parent->parent->color = RBTREE_RED;
                right_rotate(t,z->parent->parent);
            }
        }
            // z의 부모가 조부모의 왼쪽 서브 트리일 경우    
        else{
            y = z->parent->parent->left;

            //case4. 노드 z의 삼촌 y가 적색인 경우
            if (y->color == RBTREE_RED) {
                z->parent->color = RBTREE_BLACK;
                y->color = RBTREE_BLACK;
                z->parent->parent->color = RBTREE_RED;
                z = z->parent->parent;
            }
            // case5. z의 삼촌 y가 흑색이며 z가 오른쪽 자식인 경우
            else {
                if ( z== z->parent->left){
                    z = z->parent;
                    right_rotate(t,z);
                }
                // case 6. z의 삼촌 y가 흑색이며 z가 오르쪽 자식인 경우
                z->parent->color = RBTREE_BLACK;
                z->parent->parent->color = RBTREE_RED;
                left_rotate(t,z->parent->parent);
            }
        }
    }
    t->root->color = RBTREE_BLACK;    
}

// 삽입
node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert    
    node_t* y = t->nil;
    node_t* x = t->root;
    node_t* z = (node_t*)calloc(1, sizeof(node_t)); // 새로 삽입되는 노드

    z->key = key; // z 의 키 값 할당  다른 노드들은 key 값을 가지고 있다고 가정
    // leaf node 도달할 때 까지 탐샘
    while (x != t->nil){ 
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == t->nil) 
        t->root = z;
    else if (z->key < y->key)
        y->left = z;
    else 
        y->right = z;
    
    z->left = t->nil;
    z->right = t->nil;
    z->color = RBTREE_RED;
    rbtree_insert_fixup(t,z);
    
    return z;
}

// 찾기
node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  node_t* current = t->root; // 루트부터 시작해서 찾아내려감

  while( current != t->nil){ // nil이 아니면 계속 탐색
      if (current->key == key) // 찾는 키값과 일치하면
          return current;
      
      if (current->key < key) // 찾는 키값이 현재 키값보다 크면
          current = current->right;
      else                    // 찾는 키값이 현재 키값보다 작으면
          current = current->left;
  }
  return NULL;
}

// 최소값 찾기
node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  if (t->root == t->nil){ // t 가 루트를 가리킬때 nil 값이면 NULL 반환
      return NULL;
  }
  node_t* current = t->root; // 시작점을 루트로 할당

  while (current->left != t->nil){ // 왼쪽 (작은 쪽으로) 계속 탐색 nil 아닐때까지
      current = current->left;
  }
  return current;
}

// 최대값 찾기
node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  if (t->root == t->nil){
      return NULL;
  }
  node_t* current = t->root;

  while (current->right != t->nil){
      current = current->right;
  }
  return current;
}

// 서브트리 
void rbtree_transplant(rbtree* t, node_t* u, node_t* v){
  if (u->parent == t->nil){ // u가 루트 노드이면 v를 u 자리에
    t->root = v; // 즉 루트 노드에 v를 대체한다.
  }
  // 루트 노드가 아니면 왼쪽 노드이거나 오른쪽 노드 둘중 하나이다.
  else if (u==u->parent->left){
    u->parent->left=v;
  }
  else {
    u->parent->right =v ;
  }
  v->parent = u->parent;
}

// 이때의 x는 삭제된 색의 위치(y)를 대체할 노드
 void rbtree_delete_fixup(rbtree* t,node_t* x){
    // x가 루트가 아니며, x의 컬러가 블랙일때 반복 
    while (x !=t->root && x->color == RBTREE_BLACK){
        // case 1~4: 부모노드의 왼쪽 서브트리에 있을때
        if (x == x->parent->left){ 
            node_t* w = x->parent->right; //x의 형제노드 w

            // case1. x의 형제 노드 w가 적색일때
            if (w->color == RBTREE_RED){
                w->color = RBTREE_BLACK; // w를 블랙으로 바꾸고
                x->parent->color = RBTREE_RED; // 부모노드를 레드로 바꿈
                left_rotate(t, x->parent); // 부모노드 기준으로 좌회전
                w = x->parent->right; // 이동한 x에 대해 형제노드 다시 정의 -> case 2,3,4 로 해결
            }
            // case2. x의 형제노드 w가  흑색이며, w의 두 자식 노드가 모두 흑색인 경우
            if (w->left->color == RBTREE_BLACK && w->right->color == RBTREE_BLACK){
                w->color = RBTREE_RED; // 형제노드 w의 색을 레드로 바꾸고(x-extrablack&  w에서  추출> w->red)
                x = x ->parent; // x의 부모위치를 새로운 x로 설정
            } // 새로운x가 rea and black 이면 black 으로 아니면 case 1.2.3.4 생각
            // case3. x의 형제노드w가 흑색이며, w의 왼쪽 노드가 레드, 오른쪽 노드가 흑색일때
            else {
                if (w->right->color == RBTREE_BLACK){
                w->left->color = RBTREE_BLACK; // w의 왼쪽 노드를 블랙으로
                w->color = RBTREE_RED; // w를 레드로
                right_rotate(t,w); // w를 기준으로 우회전
                w = x->parent->right; // w를  새로운  위치로 조정 - > case4 
            }
            // case4. x의 형제 노드가 흑색이며, w의 오른쪽 자식 노드가 red일때   
            w->color = x->parent->color; // w의 컬러를 부모노드와 바꿈
            x->parent->color = RBTREE_BLACK; // 부모노드를 블랙으로
            w->right->color = RBTREE_BLACK; // 형제노드w의 오른쪽 노드도 블랙으로
            left_rotate(t,x->parent); // 부모노드를 기준으로 좌회전
            x = t-> root; // x를 부모노드 루트로 재설정
            }
        }
        // case 5~8 right case / case1~4의 반대 경우
        else {
            node_t *w = x->parent->left;

            // case 5. x의 형제 w가 적색인 경우
            if (w->color == RBTREE_RED){
                w->color = RBTREE_BLACK;
                x->parent->color = RBTREE_RED;
                right_rotate(t,x->parent);
                w = x->parent->left;
            } 
            // case 6.
            if (w->right->color == RBTREE_BLACK && w->left->color == RBTREE_BLACK){
                w->color = RBTREE_RED;
                x = x->parent;
            }
            // case 7.
            else {
                if (w->left->color == RBTREE_BLACK){
                w->right->color = RBTREE_BLACK;
                w->color = RBTREE_RED;
                left_rotate(t,w);
                w = x->parent->left;
            }
            // case8.
            w->color = x->parent->color;
            x->parent->color = RBTREE_BLACK;
            w->left->color =RBTREE_BLACK;
            right_rotate(t,x->parent);
            x = t->root;
            }
        } 
    }
    x->color =RBTREE_BLACK; // 부모노드를 블랙으로
 }
// z 는  트리에서 삭제될 노드 , y는 z 를 대체할 노드
// z가 하나 이하의 자식을 가질경우 y -> z 가리키도록 설정되며 삭제된다.
// z가 두개의 자식을 가질 경우 y는 z의 직후 원소로 설정되며 y는 z의 위치로 이동한다.
// x는 y의 원래 위치로 이동하는 노드
int rbtree_erase(rbtree* t,node_t* z){
   // TODO: implement erase

    node_t* y; 
    node_t* x;
    color_t yOriginalColor; // 원래 컬러 저장하기위해 추후 black 이면 문제가 됨 -> fixup

    y = z;
    yOriginalColor = y->color; // y의 색이 변경될 수 있으므로 저장
    // z의 자식노드가 1개 이하이면
    if (z->left == t->nil){
        x = z->right;
        rbtree_transplant(t,z,z->right);
    }
    else if (z->right == t->nil){
        x = z->left;
        rbtree_transplant(t,z,z->left);
    }
    else{ // z의 자식 노드가 두개일때
        y = z->right;
        while(y->left != t->nil){ // 직후 원소 찾기
            y = y->left;
        }
        yOriginalColor = y->color;
        x = y->right;

        if (y->parent == z){
            x->parent = y;
        }
        else {
            rbtree_transplant(t,y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        rbtree_transplant(t, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    } 

    if (yOriginalColor == RBTREE_BLACK){ // y의 컬러가 원래 블랙이면 문제가 됨
        rbtree_delete_fixup(t,x); // 재조정
    }

    free(z);
    
    return 0;
}

// 중위순회
void subtree_to_array(const rbtree* t, node_t* current, key_t* arr, size_t n,  int* i){
    if (current == t->nil)
        return;

    subtree_to_array(t, current->left, arr, n, i);
    if (*i < n){
        arr[*i] = current->key;
            *i += 1;
    }
    else
        return;
    subtree_to_array(t, current->right, arr, n, i);
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
    if (t->root == t->nil ){
        return 0;
    }
    int i = 0;
    subtree_to_array(t, t->root, arr, n, &i);

    return 0;
}