#include <stdio.h>
#define ddisp printf("hello world\n")  //���main.cû�� include <stdio.h>��ᱨ��
#define SQUARE(X) (X) *(X)
#define XNAME(n) (x ## n)

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) ((x)<0 ? -(x) : (x))

struct names
{
  char firstname[20];
  char lastname[20];
};    //struct declare

extern void disp();  //function declare

#ifndef NAME
#define NAME "xujiashu"
#endif // NAME

double sum(int, ...);
