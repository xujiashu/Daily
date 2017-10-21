#include <stdio.h>
#include <stdlib.h>
#include"huarongd.h"
//#define TESTBIN
//#define TESTFUNC

//the PointB index is (Index-2)
int PointA[2][5] = {
  {P00, P01, P02, P03, P04},
  {P10, P11, P12, P13, P14}
};

int PointB[2][5] = {
  {P00, P01, P02, P03, P04},
  {P10, P11, P12, P13, P14}
};

char allDirec[4] = {'u', 'd', 'l', 'r'};




//static int HRR[4][5];

#ifdef TESTBIN
static void DispBinary(int);
#endif

int main()
{
#ifdef TESTFUNC
  static int HRR[4][5] = {
    {5,5,1,1,0},
    {4,4,1,2,3},
    {2,3,5,6,6},
    {0,1,4,6,6}
    };
  mapCode testCode= {0,0,{3,0},{0,4}};
  graphToCode(&testCode, HRR);
  printf("%d, %d \n", testCode.codea, testCode.codeb);
  codeToGraph(&testCode, HRR);
  int i,j;
  for(i=0; i<4; i++)
  {
    for(j=0; j<5; j++)
    {
      printf("%d ", HRR[i][j]);
    }
    putchar('\n');
  }


#endif // TESTFUNC

#ifdef TESTBIN
  DispBinary(Boss);
  DispBinary(Bing);
  DispBinary(ZFH);
  DispBinary(ZFT);
  DispBinary(GYH);
  DispBinary(GYT);
  DispBinary(Empty);
  printf("%d Hello world!\n", sizeof(int));
  int i,j;
  for(i=0; i<4; i++)
  {
    if(i<2)
    {
      for(j=0; j<5; j++)
        DispBinary(PointA[i][j]);
    }
    else
    {
      for(j=0; j<5; j++)
        DispBinary(PointB[i-2][j]);
    }
  }
#endif

//main()
  struct hrroad Hrrd;
  Road fleeWay = &Hrrd;
  InitList(fleeWay);
  int startGraph[4][5];
  int i, j;
  puts("First Graph: ");
  for(i=0; i<4; i++)
    for(j=0; j<5; j++)
      scanf("%d", &startGraph[i][j]);
  while(getchar() != '\n')
    continue;
  mapCode firstCode;
  graphToCode(&firstCode, startGraph);
  NextStep(firstCode, fleeWay);

  while(true)
  {
    if(goForward(fleeWay))
    {
      if(isFlee())
        break;
      else
        continue;
    }
    else
      Retreat(fleeWay);
  }
  disp(fleeWay);
  puts("Bye!");


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
