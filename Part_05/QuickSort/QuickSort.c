#include <stdio.h>

void Swap(int *A, int *B)
{
  int Temp = *A;
  *A = *B;
  *B = Temp;
}

int Partition(int DataSet[], int Left, int Right)
{
  int First = Left;
  int Pivot = DataSet[First]; // Pivot은 기준 요소

  ++Left;

  while (Left <= Right)
  {
    // Left와 Right는 양 끝에서부터 기준 대상보다 크거나 작은 요소를 탐색하는 정찰병이다. 이 두 변수가 만나면 while 반복문은 종료된다.
    while (DataSet[Left] <= Pivot && Left < Right)
      ++Left;

    while (DataSet[Right] > Pivot && Left <= Right)
      --Right;

    if (Left < Right)
      Swap(&DataSet[Left], &DataSet[Right]);
    else
      break;
  }

  Swap(&DataSet[First], &DataSet[Right]);

  return Right;
}

void QuickSort(int DataSet[], int Left, int Right)
{
  if (Left < Right)
  {
    int Index = Partition(DataSet, Left, Right);

    QuickSort(DataSet, Left, Index - 1);
    QuickSort(DataSet, Index + 1, Right);
  }
}

int main()
{
  int DataSet[] = {6, 4, 2, 3, 1, 5};
  int Length = sizeof DataSet / sizeof DataSet[0];
  int i = 0;

  QuickSort(DataSet, 0, Length - 1);

  for (i = 0; i < Length; i++)
  {
    printf("%d ", DataSet[i]);
  }

  printf("\n");

  return 0;
}
