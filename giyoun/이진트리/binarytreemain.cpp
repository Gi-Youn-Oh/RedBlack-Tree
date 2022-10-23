#include "binarytree.h"
#include "binarytreetraversal.h"

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
    // 순회를 이용해 트리를 출력
    if (pBinTree != NULL){
        printf("Preorder Traveral\n");
        PreorderBinTree(pBinTree);

        printf("\nInorder Traveral\n");
        InorderBinTree(pBinTree);

        printf("\nPostorder Traveral\n");
        PostorderBinTree(pBinTree);
        printf("\n");
        deleteBinTree(pBinTree);
    }

    return 0;
}