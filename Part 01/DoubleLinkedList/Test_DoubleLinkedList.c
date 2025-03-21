#include "DoubleLinkedList.h"

int main()
{
  int i = 0;
  int Count = 0;
  Node *List = NULL;
  Node *Current = NULL;
  Node *NewNode = NULL;

  // 노드 5개 추가
  for (i = 0; i < 5; i++)
  {
    NewNode = DLL_CreateNode(i);
    DLL_AppendNode(&List, NewNode);
  }

  // 리스트 출력
  Count = DLL_GetNodeCount(List);
  for (i = 0; i < Count; i++)
  {
    Current = DLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->Data);
  }

  // 리스트의 3번째 칸 뒤에 노드 삽입
  printf("\nInserting 3000 After [2]...\n");

  NewNode = DLL_CreateNode(3000);
  Current = DLL_GetNodeAt(List, 2);
  DLL_InsertAfter(Current, NewNode);

  // 리스트 출력
  Count = DLL_GetNodeCount(List);
  for (i = 0; i < Count; i++)
  {
    Current = DLL_GetNodeAt(List, i);
    printf("List[%d] : %d\n", i, Current->Data);
  }

  // 모든 노드를 리스트에서 제거
  printf("\nDestroying List...\n");

  Count = DLL_GetNodeCount(List);

  for (int i = 0; i < Count; i++)
  {
    Current = DLL_GetNodeAt(List, 0);

    if (Current != NULL)
    {
      DLL_RemoveNode(&List, Current);
      DLL_DestroyNode(Current);
    }
  }

  return 0;
}