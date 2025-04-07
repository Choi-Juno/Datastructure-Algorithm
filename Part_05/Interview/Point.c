/**
 * @file Point.c
 * @author Juno Choi (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-04-07
 *
 * @copyright Copyright (c) 2025
 * @description qsort()를 이용해 14142번째 고객의 포인트를 찾기
 */

#include "Point.h"
#include <stdlib.h>
#include <stdio.h>

int ComparePoint(const void *_elem1, const void *_elem2)
{
  Point *elem1 = (Point *)_elem1;
  Point *elem2 = (Point *)_elem2;

  if (elem1->point > elem2->point)
    return -1;
  else if (elem1->point < elem2->point)
    return 1;
  else
    return 0;
}

int main()
{
  int Length = sizeof DataSet / sizeof DataSet[0];

  qsort((void *)DataSet, Length, sizeof(Point), ComparePoint);

  printf("14142번째 고객 ID: %d\n", DataSet[14142].id);
  printf("14142번째 고객 포인트 : %f\n", DataSet[14142].point);

  return 0;
}