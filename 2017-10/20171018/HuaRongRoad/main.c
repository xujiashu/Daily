#include <stdio.h>
#include <stdlib.h>
#include"huarongd.h"
//#define TESTBIN

//the PointB index is (Index-3)
int PointA[3][4] = {
  {A00, A01, A02, A03},
  {A10, A11, A12, A13},
  {A20, A21, A22, A23}
};

int PointB[2][4] = {
  {B30, B31, B32, B33},
  {B40, B41, B42, B43}
};

#ifdef TESTBIN
static void DispBinary(int);
#endif
static int HRR[5][4];

int main()
{
#ifdef TESTBIN
  DispBinary(Boss);
  DispBinary(Bing);
  DispBinary(HZ);
  DispBinary(Empty);
  printf("%d Hello world!\n", sizeof(int));
  int i,j;
  for(i=0; i<5; i++)
  {
    if(i<3)
    {
      for(j=0; j<4; j++)
        DispBinary(PointA[i][j]);
    }
    else
    {
      for(j=0; j<4; j++)
        DispBinary(PointB[i-3][j]);
    }
  }
#endif

  memset(HRR, 0, 20 * sizeof(int));


  return 0;
}

#ifdef TESTBIN
static void DispBinary(int num)
{
  int i, j;
  j = sizeof(int)*8;
  for(i=0; i<j; i++)
  {
    printf("%d", (num>>(j-i-1)&0x1));
  }
  putchar('\n');
}
#endif
