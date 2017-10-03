#include<stdio.h>

int main()
{
  //point to an array contain 2 int
  //[] is prior than *
  int (* pz)[2];
  int zippo[4][2];
  pz = zippo;

  //Is (*pa)[1] equal to *pa ?
  int (*pa)[1];
  int (*pb)[1];
  int *pc;
  pa = (int [][1]){1,2,3};
  pb = pa;
  //pc = pa;  //invalid

  return 0;

}
