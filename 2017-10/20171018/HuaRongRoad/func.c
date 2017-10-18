#include"huarongd.h"
#include<stdio.h>
#include<string.h>

extern int PointA[3][4];
extern int PointB[2][4];

bool moveBoss(int (*HRR)[4], struct position * pt)
{
  return true;
}

bool moveHZ(int (*HRR)[4], struct position * pt)
{
  return true;
}

bool moveGY(int (*HRR)[4], struct position * pt)
{
  return true;
}

mapCode storeMap(const int (*HRR)[4])
{
  int codeA;
  int codeB;
  codeA=codeB=0;
  mapCode theCode = {codeA, codeB};


  return theCode;
}
