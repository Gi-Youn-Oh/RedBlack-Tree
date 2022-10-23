#include "binarytree.h"
using namespace std;
// MakeBinTree()
BinTree* MakeBinTree(BinTreeNode rootNode){
    BinTree *pReturn = NULL;
    pReturn =(BinTree*)malloc(sizeof(BinTree));
    if(pReturn != NULL){
        pReturn->pRootNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
        if(pReturn->pRootNode != NULL) {
            *pReturn-> pRootNode = rootNode;
            pReturn-> pRootNode-> pLeftChild = NULL;
            pReturn-> pRootNode-> pRightChild =NULL;
        }
        else{
            cout << "메모리 할당 오류" << endl;
        }
    }
    else
        cout <<"메모리 할당 오류" << endl;
    return pReturn;
}
// 입력변수로 루트노드가 될 값을 받고 루트노드로 설정한다. 설정 후 루트 노드의 자식 링크를 각각 NULL 값으로 초기화해주고 이진트리를 반환한다.

//InsertChildNode()
BinTreeNode* inseertLeftChileNode(BinTreeNode* pParentNode, BinTreeNode element){
    BinTreeNode* pReturn = NULL;
    if (pParentNode != NULL){
        if (pParentNode ->pLeftChild ==NULL){
            pParentNode ->pLeftChild = (BinTreeNode*)malloc(sizeof(BinTreeNode)); 
            *pParentNode->pLeftChild =element; // 부모 노드의 왼쪽 자식 링크를 element로 설정
            pParentNode->pLeftChild->pLeftChild =NULL; // 새로운 노드 자식링크 초기화
            pParentNode->pLeftChild->pRightChild=NULL; // 새로운 노드 자식링크 초기화
            pReturn = pParentNode->pLeftChild; // 반환값 설정
        }
        else {
            cout << "이미 노드가 존재합니다." << endl;
        }
    }
    return pReturn;
}// 왼쪽 자식 노드 추가

BinTreeNode* inseertLeftChileNode(BinTreeNode* pParentNode, BinTreeNode element){
    BinTreeNode* pReturn = NULL;
    if (pParentNode != NULL){
        if (pParentNode ->pRightChild ==NULL){
            pParentNode ->pRightChild = (BinTreeNode*)malloc(sizeof(BinTreeNode)); 
            *pParentNode->pRightChild =element; // 부모 노드의 왼쪽 자식 링크를 element로 설정
            pParentNode->pRightChild->pLeftChild =NULL; // 새로운 노드 자식링크 초기화
            pParentNode->pRightChild->pRightChild=NULL; // 새로운 노드 자식링크 초기화
            pReturn = pParentNode->pRightChild; // 반환값 설정
        }
        else {
            cout << "이미 노드가 존재합니다." << endl;
        }
    }
    return pReturn;
}// 오른쪽 자식 노드 추가

// getNode()
BinTreeNode* getRootNode(BinTree* pBinTree){
    BinTreeNode* pReturn = NULL;
    if (pBinTree != NULL) {
        pReturn = pBinTree->pRootNode;
    }
    return pReturn;
} // 루트 노드 반환

BinTreeNode* getLeftChildNode(BinTreeNode* pNode){
    BinTreeNode* pReturn = NULL;
    if (pNode != NULL) {
        pReturn = pNode->pLeftChild;
    }
    return pReturn;
} // 왼쪽 자식 노드 반환

BinTreeNode* getRightChildNode(BinTreeNode* pNode){
    BinTreeNode* pReturn = NULL;
    if (pNode != NULL) {
        pReturn = pNode->pRightChild;
    }
    return pReturn;
} // 오른쪽 자식 노드 반환

//deleteBinTree(),deleteBinTreeNode()
void deleteBinTree(BinTree* pBinTree){
        deleteBinTreeNode(pBinTree -> pRootNode);
        free(pBinTree);
} //이진트리 삭제
void deleteBinTreeNode(BinTreeNode* pNode){
    if (pNode != NULL){
        deleteBinTreeNode(pNode ->pLeftChild);
        deleteBinTreeNode(pNode ->pRightChild);
        free(pNode);
    }
}// 노드 삭제