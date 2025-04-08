#include "DoubleLinkedList.h"

// 리스트 출력 함수
void PrintList(Node *Head)
{
  Node *Current = Head;
  printf("List: ");
  while (Current != NULL)
  {
    printf("%d ", Current->Data);
    Current = Current->NextNode;
  }
  printf("\n");
}

// 역순 출력 함수
void PrintReverseList(Node *Head)
{
  // 마지막 노드 찾기
  Node *Current = Head;
  while (Current != NULL && Current->NextNode != NULL)
  {
    Current = Current->NextNode;
  }

  printf("Reverse List: ");
  while (Current != NULL)
  {
    printf("%d ", Current->Data);
    Current = Current->PrevNode;
  }
  printf("\n");
}

// 테스트 케이스 1: 일반적인 정렬
void TestCase1()
{
  printf("\n=== 테스트 케이스 1: 일반적인 정렬 ===\n");
  Node *List = NULL;

  // 5, 2, 8, 1, 9 순서로 노드 추가
  DLL_AppendNode(&List, DLL_CreateNode(5));
  DLL_AppendNode(&List, DLL_CreateNode(2));
  DLL_AppendNode(&List, DLL_CreateNode(8));
  DLL_AppendNode(&List, DLL_CreateNode(1));
  DLL_AppendNode(&List, DLL_CreateNode(9));

  printf("정렬 전: ");
  PrintList(List);

  DLL_InsertionSort(&List);

  printf("정렬 후: ");
  PrintList(List);
  printf("역순 출력: ");
  PrintReverseList(List);

  // 메모리 해제
  while (List != NULL)
  {
    Node *Temp = List;
    List = List->NextNode;
    DLL_DestroyNode(Temp);
  }
}

// 테스트 케이스 2: 이미 정렬된 리스트
void TestCase2()
{
  printf("\n=== 테스트 케이스 2: 이미 정렬된 리스트 ===\n");
  Node *List = NULL;

  // 1, 2, 3, 4, 5 순서로 노드 추가
  for (int i = 1; i <= 5; i++)
  {
    DLL_AppendNode(&List, DLL_CreateNode(i));
  }

  printf("정렬 전: ");
  PrintList(List);

  DLL_InsertionSort(&List);

  printf("정렬 후: ");
  PrintList(List);
  printf("역순 출력: ");
  PrintReverseList(List);

  // 메모리 해제
  while (List != NULL)
  {
    Node *Temp = List;
    List = List->NextNode;
    DLL_DestroyNode(Temp);
  }
}

// 테스트 케이스 3: 역순 정렬된 리스트
void TestCase3()
{
  printf("\n=== 테스트 케이스 3: 역순 정렬된 리스트 ===\n");
  Node *List = NULL;

  // 5, 4, 3, 2, 1 순서로 노드 추가
  for (int i = 5; i >= 1; i--)
  {
    DLL_AppendNode(&List, DLL_CreateNode(i));
  }

  printf("정렬 전: ");
  PrintList(List);

  DLL_InsertionSort(&List);

  printf("정렬 후: ");
  PrintList(List);
  printf("역순 출력: ");
  PrintReverseList(List);

  // 메모리 해제
  while (List != NULL)
  {
    Node *Temp = List;
    List = List->NextNode;
    DLL_DestroyNode(Temp);
  }
}

// 테스트 케이스 4: 중복된 값이 있는 리스트
void TestCase4()
{
  printf("\n=== 테스트 케이스 4: 중복된 값이 있는 리스트 ===\n");
  Node *List = NULL;

  // 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 순서로 노드 추가
  int data[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  for (int i = 0; i < 11; i++)
  {
    DLL_AppendNode(&List, DLL_CreateNode(data[i]));
  }

  printf("정렬 전: ");
  PrintList(List);

  DLL_InsertionSort(&List);

  printf("정렬 후: ");
  PrintList(List);
  printf("역순 출력: ");
  PrintReverseList(List);

  // 메모리 해제
  while (List != NULL)
  {
    Node *Temp = List;
    List = List->NextNode;
    DLL_DestroyNode(Temp);
  }
}

// 테스트 케이스 5: 빈 리스트
void TestCase5()
{
  printf("\n=== 테스트 케이스 5: 빈 리스트 ===\n");
  Node *List = NULL;

  printf("정렬 전: ");
  PrintList(List);

  DLL_InsertionSort(&List);

  printf("정렬 후: ");
  PrintList(List);
}

// 테스트 케이스 6: 단일 노드 리스트
void TestCase6()
{
  printf("\n=== 테스트 케이스 6: 단일 노드 리스트 ===\n");
  Node *List = NULL;

  DLL_AppendNode(&List, DLL_CreateNode(42));

  printf("정렬 전: ");
  PrintList(List);

  DLL_InsertionSort(&List);

  printf("정렬 후: ");
  PrintList(List);
  printf("역순 출력: ");
  PrintReverseList(List);

  // 메모리 해제
  DLL_DestroyNode(List);
}

int main()
{
  printf("더블 링크드 리스트 삽입 정렬 테스트\n");
  printf("==================================\n");

  TestCase1(); // 일반적인 정렬
  TestCase2(); // 이미 정렬된 리스트
  TestCase3(); // 역순 정렬된 리스트
  TestCase4(); // 중복된 값이 있는 리스트
  TestCase5(); // 빈 리스트
  TestCase6(); // 단일 노드 리스트

  return 0;
}