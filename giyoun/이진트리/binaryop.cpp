# pragma once
# include "binarytree.h"

BinTree* copyBinTree(BinTree* pSource) { //복사
    BinTree* pReturn = NULL;
    if (pSource != NULL){
        pReturn = (BinTree*)malloc(sizeof(BinTree));
        if(pReturn != NULL){
            pReturn->pRootNode = copyBinTreeNode(pSource->pRootNode);
         
        }
    }
    return pReturn;
}

BinTreeNode* copyBinTreeNode(BinTreeNode* pSourceNode){
    BinTreeNode* pReturn = NULL; 
    if (pSourceNode != NULL){
        pReturn = (BinTreeNode*)malloc(sizeof(BinTreeNode));
        if(pReturn != NULL){
            *pReturn = *pSourceNode; // 현재노드
            pReturn->pLeftChild = copyBinTreeNode(getLeftChildNode(pSourceNode)); // 왼쪽 서브트리
            pReturn->pRightChild = copyBinTreeNode(getRightChildNode(pSourceNode)); // 오른쪽 서브트리
            
        }
    }
    return pReturn;
}

int equalBinTree(BinTree* pFirst, BinTree* pSecond){ //동일성검사
    int ret = FALSE;
    if (pFirst == NULL && pSecond == NULL){
        ret = TRUE;
    }
    else if (pFirst != NULL && pSecond != NULL && equalBinTreeNode(pFirst->pRootNode, pSecond->pRootNode)==TRUE){
        ret = TRUE;
    }
    return ret;
}
int equalBinTreeNode(BinTreeNode* pFirst, BinTreeNode* pSecond){
    int ret = FALSE;
    if (pFirst == NULL && pSecond == NULL){
        ret = TRUE;
    }
    else if (pFirst != NULL && pSecond != NULL
    && pFirst->data == pSecond->data //  현재노드
    && equalBinTreeNode(pFirst->pLeftChild,pSecond->pLeftChild) == TRUE // 왼쪽 서브트리
    && equalBinTreeNode(pFirst->pRightChild,pSecond->pRightChild) == TRUE) { //오른쪽 서브트리
    ret = TRUE;
    }
    return ret;
}

int getNodeCount(BinTree* pSource){ // 노드 개수 구하기
    int ret = 0;
    if (pSource != NULL) {
        ret = getNodeCountNode(pSource -> pRootNode);
    }
    return ret;
}
int getNodeCountNode(BinTreeNode* pSource){
    int ret = 0;
    if (pSource != NULL){
        ret = getNodeCountNode(pSource->pLeftChild) //왼쪾 서브 트리
        + getNodeCountNode(pSource->pRightChild) // 오른쪽 서브 트리
        +1; // 현재노드
    }
    return ret;
}

int getLeafNodeCount(BinTree* pSource) { // 단말 노드 구하기
    int ret = 0;
    if (pSource != NULL){
        ret = getLeafNodeCountNode(pSource->pRootNode);
    }
    return ret;
}
int getLeafNodeCountNode(BinTreeNode* pSource){
    int ret = 0;
    if (pSource != NULL){
        if (pSource->pLeftChild == NULL && pSource->pRightChild == NULL){
            ret = 1;
        }
        else {
            ret = getLeafNodeCountNode(pSource->pLeftChild)
                    + getLeafNodeCountNode(pSource->pRightChild);
        }
    }
    return ret;
}

int getHeight(BinTree* pSource){// 이진 트리의 높이 구하기
    int ret = 0;
    if (pSource != NULL){
        ret = getHeightNode(pSource->pRootNode);
    }
    return ret;
}
int getHeightNode(BinTreeNode* pSource){
    int ret = 0;
    if (pSource != NULL){
        if (pSource->pLeftChild == NULL && pSource->pRightChild == NULL){
            ret = 1;
        }
        else {
            int leftChildHeight = getHeightNode(pSource->pLeftChild);
            int rightChildHeight = getHeightNode(pSource->pRightChild);
            if (leftChildHeight >= rightChildHeight){
                ret = leftChildHeight + 1;
            }
            else {
                ret = rightChildHeight +1;
            }
        }
    }
    return ret;
}