#include "binarytree.h"
#include "binarytreetraversal.h"

//전위 순회
void PreorderBinTree(BinTree *pBinTree){
    if (pBinTree != NULL) {
        PreorderBinTreeNode(pBinTree->pRootNode);
    }
}
void PreorderBinTreeNode(BinTreeNode *pRootNode){
    if (pRootNode != NULL){
        printf("%c", pRootNode->data);
        PreorderBinTreeNode(pRootNode->pLeftChild);
        PreorderBinTreeNode(pRootNode->pRightChild);
    }
}

// 중위 순회

void InorderBinTree(BinTree *pBinTree){
    if (pBinTree != NULL){
        InorderBinTreeNode(pBinTree->pRootNode);
    }
}
void InorderBinTreeNode(BinTreeNode *pRootNode){
    if (pRootNode != NULL){
        InorderBinTreeNode(pRootNode->pLeftChild);
        printf("%c", pRootNode->data);
        InorderBinTreeNode(pRootNode->pRightChild);
    }
}

// 후위순회

void PostorderBinTree(BinTree *pBinTree){
    if (pBinTree != NULL){
        PostorderBinTreeNode(pBinTree ->pRootNode);
    }
}
void PostorderBinTreeNode(BinTreeNode *pRootNode){
    if (pRootNode != NULL){
        PostorderBinTreeNode(pRootNode->pLeftChild);
        PostorderBinTreeNode(pRootNode->pRightChild);
        printf("%c", pRootNode->data);
    }
}
