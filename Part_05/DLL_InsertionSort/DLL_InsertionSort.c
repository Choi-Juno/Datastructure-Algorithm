#include "DoubleLinkedList.h"

void DLL_InsertionSort(Node **Head)
{
  Node *SortedHead = NULL;
  Node *Current = *Head;
  Node *Temp = NULL;

  while (Current != NULL)
  {
    // 다음 노드를 미리 저장
    Temp = Current->NextNode;

    // 현재 노드의 링크를 초기화
    Current->NextNode = NULL;
    Current->PrevNode = NULL;

    if (SortedHead == NULL)
    {
      // 첫 번째 노드는 정렬된 리스트의 헤드가 됨
      SortedHead = Current;
    }
    else
    {
      Node *Search = SortedHead;
      Node *Prev = NULL;

      // 적절한 삽입 위치 찾기
      while (Search != NULL && Search->Data < Current->Data)
      {
        Prev = Search;
        Search = Search->NextNode;
      }

      // 노드 삽입
      if (Prev == NULL)
      {
        // 리스트의 맨 앞에 삽입
        Current->NextNode = SortedHead;
        SortedHead->PrevNode = Current;
        SortedHead = Current;
      }
      else
      {
        // Prev노드 뒤에 삽입
        Current->NextNode = Search;
        Current->PrevNode = Prev;
        Prev->NextNode = Current;
        if (Search != NULL)
        {
          Search->PrevNode = Current;
        }
      }
    }

    // 다음 노드로 이동
    Current = Temp;
  }

  *Head = SortedHead;
}