#include "ArrayStack.h"

void AS_CreateStack(ArrayStack **Stack, int Capacity)
{
  // 스택을 자유 저장소에 생성
  (*Stack) = (ArrayStack *)malloc(sizeof(ArrayStack));

  // 입력된 Capacity만큼의 노드를 자유 저장소에 생성
  (*Stack)->Nodes = (Node *)malloc(sizeof(Node) * Capacity);

  // Capacity 및 Top 초기화
  (*Stack)->Capacity = Capacity;
  (*Stack)->Top = -1;
}

void AS_DestroyStack(ArrayStack *Stack)
{
  // 노드를 자유 저장소에서 해제
  free(Stack->Nodes);

  // 스택을 자유 저장소에서 해제
  free(Stack);
}

void AS_Push(ArrayStack *Stack, ElementType Data)
{
  // 스택이 가득 찼는지 확인
  if (Stack->Top == Stack->Capacity - 1)
  {
    // 스택이 가득 찼을 경우
    // 새로운 용량 계산 (현재 용량의 30% 증가)
    int AddedCapacity = (int)(Stack->Capacity * 0.3);
    if (AddedCapacity < 1)
      AddedCapacity = 1; // 최소 1개는 증가

    int NewCapacity = Stack->Capacity + AddedCapacity;

    // 새로운 크기의 메모리 할당
    ElementType *NewNodes = (ElementType *)malloc(sizeof(ElementType) * NewCapacity);

    // 메모리 할당 실패 처리
    if (NewNodes == NULL)
    {
      printf("Memory Allocation Failed.\n");
      return;
    }

    // 기존 메모리를 새 메모리 공간으로 복사
    if (Stack->Nodes != NULL && Stack->Top >= 0)
      memcpy(NewNodes, Stack->Nodes, sizeof(ElementType) * (Stack->Capacity));

    // 기존 메모리 해제
    free(Stack->Nodes);

    // 새 메모리 할당 성공 시 스택 정보 업데이트
    Stack->Nodes = NewNodes;
    Stack->Capacity = NewCapacity;
  }

  // 데이터 삽입
  Stack->Top++;
  Stack->Nodes[Stack->Top].Data = Data;
}

ElementType AS_Pop(ArrayStack *Stack)
{
  // 스택의 용량이 70% 미만일 경우
  if (Stack->Top < (int)(Stack->Capacity * 0.7))
  {
    // 새로운 용량 계산 (현재 용량의 30% 감소)
    int NewCapacity = (int)(Stack->Capacity * 0.7);
    if (NewCapacity < 10)
      NewCapacity = 10; // 최소 10개는 설정
    ElementType *NewNodes = (ElementType *)malloc(sizeof(ElementType) * NewCapacity);

    // 메모리 할당 실패 처리
    if (NewNodes == NULL)
    {
      printf("Memory Allocation Failed.\n");
      return;
    }

    // 기존 메모리를 새 메모리 공간으로 복사
    if (Stack->Nodes != NULL && Stack->Top >= 0)
      memcpy(NewNodes, Stack->Nodes, sizeof(ElementType) * (Stack->Top + 1));

    // 기존 메모리 해제
    free(Stack->Nodes);

    // 새 메모리 할당 성공 시 스택 정보 업데이트
    Stack->Nodes = NewNodes;
    Stack->Capacity = NewCapacity;
  }

  int Position = Stack->Top--;
  return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack *Stack)
{
  return Stack->Nodes[Stack->Top].Data;
}

int AS_GetSize(ArrayStack *Stack)
{
  return Stack->Top + 1;
}

int AS_IsEmpty(ArrayStack *Stack)
{
  return (Stack->Top == -1);
}

int AS_IsFull(ArrayStack *Stack)
{
  return (Stack->Top == Stack->Capacity - 1);
}
