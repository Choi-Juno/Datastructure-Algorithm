#include "BinaryTree.h"

int main()
{
  // 노드 생성
  SBTNode *A = SBT_CreateNode('A');
  SBTNode *B = SBT_CreateNode('B');
  SBTNode *C = SBT_CreateNode('C');
  SBTNode *D = SBT_CreateNode('D');
  SBTNode *E = SBT_CreateNode('E');
  SBTNode *F = SBT_CreateNode('F');
  SBTNode *G = SBT_CreateNode('G');

  // 트리에 노드 추가
  A->Left = B;
  B->Left = C;
  B->Right = D;

  A->Right = E;
  E->Left = F;
  E->Right = G;

  // 트리 출력
  printf("Preorder ...\n");
  SBT_PreorderPrintTree(A);
  printf("\n\n");

  printf("Inorder ...\n");
  SBT_InorderPrintTree(A);
  printf("\n\n");

  printf("Postorder ...\n");
  SBT_PostorderPrintTree(A);
  printf("\n\n");

  // 트리 소멸
  SBT_DestroyTree(A);

  return 0;
}