#include "LinkedList.h"

// 노드 생성
Node *SLL_CreateNode(ElementType NewData)
{
  Node *NewNode = (Node *)malloc(sizeof(Node));

  NewNode->Data = NewData;
  NewNode->NextNode = NULL;

  return NewNode;
}

// 노드 소멸
void SLL_DestroyNode(Node *Node)
{
  free(Node);
}

// 노드 추가
void SLL_AppendNode(Node **Head, Node *NewNode)
{
  if (*Head == NULL)
  {
    *Head = NewNode;
  }
  else
  {
    Node *Tail = *Head;
    while (Tail->NextNode != NULL)
    {
      Tail = Tail->NextNode;
    }
    Tail->NextNode = NewNode;
  }
}

// 노드 삽입
void SLL_InsertAfter(Node *Current, Node *NewNode)
{
  NewNode->NextNode = Current->NextNode;
  Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node **Head, Node *NewHead)
{
  if (Head == NULL)
  {
    *Head = NewHead;
  }
  else
  {
    NewHead->NextNode = *Head;
    *Head = NewHead;
  }
}

void SLL_RemoveNode(Node **Head, Node *Remove)
{
  if (*Head == Remove)
  {
    *Head = Remove->NextNode;
  }
  else
  {
    Node *Current = *Head;
    while (Current != NULL && Current->NextNode != Remove)
    {
      Current = Current->NextNode;
    }
    if (Current != NULL)
    {
      Current->NextNode = Remove->NextNode;
    }
  }
}

Node *SLL_GetNodeAt(Node *Head, int Location)
{
  Node *Current = Head;

  while (Current != NULL && (--Location) >= 0)
  {
    Current = Current->NextNode;
  }

  return Current;
}

int SLL_GetNodeCount(Node *Head)
{
  int Count = 0;
  Node *Current = Head;

  while (Current != NULL)
  {
    Current = Current->NextNode;
    Count++;
  }

  return Count;
}
