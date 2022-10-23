#pragma once
#include <iostream>
#define TRUE 1
#define FALSE 0
struct BinTreeNode{
    int data;
    struct BinTreeNode*pLeftChild;
    struct BinTreeNode*pRightChild;
};
struct BinTree{
    BinTreeNode* pRootNode;
};
BinTree* MakeBinTree(BinTreeNode rootNode); // 이진트리 생성
BinTreeNode* getRootNode(BinTree*pBinTree); // 루트노드 반환
BinTreeNode* inseertLeftChileNode(BinTreeNode*pParentNode,BinTreeNode element); // 왼쪽자식 노드 추가
BinTreeNode* inseertRightChileNode(BinTreeNode*pParentNode,BinTreeNode element); // 오른쪽 자식 노드 추가
BinTreeNode* getLeftChildNode(BinTreeNode* pNode); //왼쪽 자식 노드 반환
BinTreeNode* getRightChildNode(BinTreeNode* pNode); //오른쪽 자식 노드 반환
//BinTreeNode*getData();
void deleteBinTree(BinTree* pBinNode); //이진트리 삭제
void deleteBinTreeNode(BinTreeNode* pNode); //노드 삭제
// BinTreeNode는 트리에 저장되는 각각의 자료들을 의미하며 실제값 data와 자식 노드를 가리키는 링크를 포함한다.
// 이때 이진트리이므로 자식은 왼쪽자식, 오른쪽 자식 최대 2개만 존재한다.
// BinTree는 실제 이진 트리를 의미한다. 내부 변수는 오직 루트 노드만 존재한다.
// 이루트 노드의 링크를 이용해 모든 값에 접근할 것이다.
