#include "LinkedList.h"

void SLL_MoveToFront(Node **Head, int Target)
{
  Node *Current = *Head;
  Node *Previous = NULL;
  Node *Match = NULL;

  while (Current != NULL)
  {
    if (Current->Data == Target)
    {
      Match = Current;

      if (Previous == NULL)
      {
        // 자신의 이전 노드와 다음 노드를 연결
        Previous->NextNode = Current->NextNode;

        // 자신을 리스트의 헤드로 옮기기
        Current->NextNode = *Head;
        *Head = Current;
      }
      break;
    }
    else
    {
      Previous = Current;
      Current = Current->NextNode;
    }
  }
  return Match;
}

int SLL_MoveToFrontArray(int *Array, int Size, int Target)
{
  int i = 0;
  int targetIndex = -1; // 찾지 못한 경우 -1 반환

  for (i = 0; i < Size; i++)
  {
    if (Array[i] == Target)
    {
      int temp = Array[0];
      Array[0] = Array[i];
      Array[i] = temp;
      targetIndex = i;
      break;
    }
  }
  return targetIndex;
}

Node *SLL_Transpose(Node **Head, int Target)
{
  Node *Current = *Head;
  Node *PPrevious = NULL;
  Node *Previous = NULL;
  Node *Match = NULL;

  while (Current != NULL)
  {
    if (Current->Data == Target)
    {
      Match = Current;
      if (Previous != NULL)
      {
        if (PPrevious != NULL)
          PPrevious->NextNode = Current;
        else
          *Head = Current;

        Previous->NextNode = Current->NextNode;
        Current->NextNode = Previous;
      }
      break;
    }
    else
    {
      if (Previous != NULL)
        PPrevious = Previous;

      Previous = Current;
      Current = Current->NextNode;
    }
  }
  return Match;
}

int SLL_TransposeArray(int *Array, int Size, int Target)
{
  int i = 0;
  int targetIndex = -1;

  for (i = 0; i < Size; i++)
  {
    if (Array[i] == Target)
    {
      targetIndex = i;
      if (i != 0)
      {
        int Temp = Array[i - 1];
        Array[i - 1] = Array[i];
        Array[i] = Temp;
      }
      break;
    }
  }
  return targetIndex;
}

Node *SLL_FrequencyCount(Node **Head, int Target)
{
  Node *Current = *Head;
  Node *Match = NULL;
  int Frequency = 0;

  while (Current != NULL)
  {
  }
}
