#include "DoubleLinkedList.h"

// 노드 생성
Node *DLL_CreateNode(ElementType NewData)
{
  Node *NewNode = (Node *)malloc(sizeof(Node));

  NewNode->Data = NewData;
  NewNode->PrevNode = NULL;
  NewNode->NextNode = NULL;

  return NewNode;
}

// 노드 소멸
void DLL_DestroyNode(Node *Node)
{
  free(Node);
}

// 노드 추가
void DLL_AppendNode(Node **Head, Node *NewNode)
{
  // 헤드 노드가 NULL이라면 새로운 노드가 Head가 된다.
  if (*Head == NULL)
  {
    *Head = NewNode;
  }
  else
  { // Tail을 찾아 Append한다
    Node *Tail = *Head;
    while (Tail->NextNode != NULL)
    {
      Tail = Tail->NextNode;
    }
    Tail->NextNode = NewNode;
    NewNode->PrevNode = Tail; // 기존 테일을 새로운 테일의 PrevNode가 가리킨다.
  }
}

// 노드 삽입
void DLL_InsertAfter(Node *Current, Node *NewNode)
{
  NewNode->NextNode = Current->NextNode;
  NewNode->PrevNode = Current;

  if (Current->NextNode != NULL)
  {
    Current->NextNode->PrevNode = NewNode;
    Current->NextNode = NewNode;
  }
}

// 노드 제거
void DLL_RemoveNode(Node **Head, Node *Remove)
{
  // Head노드가 제거할 노드일 떄
  if (*Head == Remove)
  {
    *Head = Remove->NextNode;

    if (*Head != NULL)
    {
      (*Head)->PrevNode = NULL;
    }

    Remove->PrevNode = NULL;
    Remove->NextNode = NULL;
  }
  else // Head노드가 제거할 노드가 아닐 때
  {
    Node *Temp = Remove;

    if (Remove->PrevNode != NULL)
    {
      Remove->PrevNode->NextNode = Temp->NextNode;
    }
    if (Remove->NextNode != NULL)
    {
      Remove->NextNode->PrevNode = Temp->PrevNode;
    }

    Remove->PrevNode = NULL;
    Remove->NextNode = NULL;
  }
}

// 노드 탐색
Node *DLL_GetNodeAt(Node *Head, int Location)
{
  Node *Current = Head;

  while (Current != NULL && (--Location) >= 0)
  {
    Current = Current->NextNode;
  }

  return Current;
}

// 노드 개수 세기
int DLL_GetNodeCount(Node *Head)
{
  unsigned int Count = 0;
  Node *Current = Head;

  while (Current != NULL)
  {
    Current = Current->NextNode;
    Count++;
  }

  return Count;
}

// 노드 출력
void DLL_PrintList(Node *_Node)
{
  if (_Node->PrevNode == NULL)
    printf("Prev: NULL\n");
  else
    printf("Prev: %d\n", _Node->PrevNode->Data);

  printf("Current: %d\n", _Node->Data);

  if (_Node->NextNode == NULL)
    printf("Next: NULL\n");
  else
    printf("Next: %d\n", _Node->NextNode->Data);
}

void PrintReverse(Node *Head)
{
  // 1. 마지막 노드를 찾음
  Node *Current = Head;
  while (Current != NULL && Current->NextNode != NULL)
  {
    Current = Current->NextNode;
  }

  // 마지막 노드부터 역순으로 출력
  int i = DLL_GetNodeCount(Head) - 1;
  while (Current != NULL)
  {
    printf("List[%d] : %d\n", i, Current->Data);
    Current = Current->PrevNode;
  }
}
