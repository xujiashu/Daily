#include<stdio.h>

static int dnum(int k)
{
  return k*2;
}

void disp(void)
{
  printf("Call static function: %d\n", dnum(10));
}
