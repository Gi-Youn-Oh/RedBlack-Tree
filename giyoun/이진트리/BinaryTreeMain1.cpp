#include "binarytree.h"
#include "binarytreetraversal.h"
#include "binarypo.h"

int main()
{
    // 트리생성
    BinTree *pBinTree =NULL;
    BinTreeNode *pNode1 = NULL, *pNode2 = NULL, *pNode3= NULL, *pNode4= NULL, *pNode5= NULL, *pNode6= NULL, *pNode7= NULL;
    BinTreeNode node = {0,};

    node.data = 'A';
    pBinTree = MakeBinTree(node);

    if (pBinTree != NULL){

        pNode1 = getRootNode(pBinTree);

        node.data = 'B';
        pNode2 = insertLeftChildNode(pNode1, node);

        node.data = 'C';
        pNode3 = insertLeftChildNode(pNode1, node);

        node.data = 'D';
        pNode4 = insertLeftChildNode(pNode2, node);

        node.data = 'E';
        pNode5 = insertLeftChildNode(pNode2, node);

        node.data = 'F';
        pNode6 = insertLeftChildNode(pNode3, node);

        node.data = 'G';
        pNode7 = insertLeftChildNode(pNode3, node);
     
    }
    int compare = FALSE;
    int count = 0;
    BinTree* pCopyBinTree = NULL ; //복사할 트리 선언
    pCopyBinTree = copyBinTree(pBinTree); //복사
    printf("기존 트리 전위 순환 방식으로 출력\n");
    PreorderBinTree(pBinTree);
    printf("\n 복사 트리 전위 순환 방식으로 출력\n");
    PreorderBinTree(pCopyBinTree);

    compare = equalBinTree(pBinTree, pCopyBinTree); //동일성 검사
    printf("\n이진 트리 비교 결과:(%d)\n", count);

    count = getNodeCount(pBinTree); //노드 개수
    printf("\n이진 트리 노드 개수:%d\n", count);
    
    count = getLeafNodeCount(pBinTree); // 단말 노드 개수
    printf("\n이진 트리 단말 노드 개수:%d\n", count);

    count = getHeight(pBinTree); // 트리의 높이
    printf("\n이진 트리의 높이:%d\n", count);
    
    deleteBinTree(pBinTree);
    deleteBinTree(pCopyBinTree);
    
    return 0;
}