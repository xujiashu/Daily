#include<stdio.h>
void DispBinary(unsigned short num)
{
  int i, j;
  j = sizeof(unsigned short)*8;
  for(i=0; i<j; i++)
  {
    printf("%d", (num>>(j-i-1)&0x1));
  }
}


main()
{
  unsigned short ushort_n;
  short short_n;
  unsigned int uint_n;
  int int_n;
  printf("ushort_n:%d\nshort_n:%d\nuint_n:%d\nint_n:%d\n",
  sizeof ushort_n, sizeof short_n, sizeof uint_n, sizeof int_n);
  ushort_n = 65535;
  DispBinary(ushort_n);
  return 0;
}
