# pragma once
# include "binarytree.h"

BinTree* copyBinTree(BinTree* pSource); // 복사
BinTreeNode* copyBinTreeNode(BinTreeNode* pSourceNode);

int equalBinTree(BinTree* pFirst, BinTree* pSecond); //동일성 검사
int equalBinTreeNode(BinTreeNode* pFirst, BinTreeNode* pSecond);

int getNodeCount(BinTree* pSource); // 노드 개수 구하기
int getNodeCountNode(BinTreeNode* pSource);

int getLeafNodeCount(BinTree* pSource); // 단말 노드 구하기
int getLeafNodeCountNode(BinTreeNode* pSource);

int getHeight(BinTree* pSource); // 이진 트리의 높이 구하기
int getHeightNode(BinTreeNode* pSource);