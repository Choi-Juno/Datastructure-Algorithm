#include <stdio.h>

void BubbleSort(int DataSet[], int Length)
{
  int i = 0;
  int j = 0;
  int temp = 0;
  int isSorted; // 정렬 여부를 확인하는 플래그

  if (Length <= 1)
    return; // 배열 길이가 1 이하면 정렬 필요 없음

  for (i = 0; i < Length - 1; i++)
  {
    isSorted = 1;                        // 매 패스 시작시 정렬되었다고 가정
    for (j = 0; j < Length - 1 - i; j++) // 수정된 부분: Length - (i + 1) 대신 Length - 1 - i 사용
    {
      if (DataSet[j] > DataSet[j + 1])
      {
        temp = DataSet[j + 1];
        DataSet[j + 1] = DataSet[j];
        DataSet[j] = temp;
        isSorted = 0; // 스왑이 발생하면 아직 정렬되지 않음
      }
    }
    if (isSorted) // 한 패스 동안 스왑이 없었다면 이미 정렬된 상태
      break;
  }
}

int main()
{
  int DataSet[] = {6, 4, 2, 3, 1, 5};
  int Length = sizeof DataSet / sizeof DataSet[0];
  int i = 0;

  printf("Original array: ");
  for (i = 0; i < Length; i++)
  {
    printf("%d ", DataSet[i]);
  }
  printf("\n");

  BubbleSort(DataSet, Length);

  printf("Sorted array: ");
  for (i = 0; i < Length; i++)
  {
    printf("%d ", DataSet[i]);
  }
  printf("\n");

  return 0;
}