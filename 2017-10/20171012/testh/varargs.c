#include<stdio.h>
#include<stdarg.h>

double sum(int lim, ...)
{
  va_list ap;
  double tot = 0;
  int i;
  va_start(ap, lim);
  for(i=0; i<lim; i++)
    tot += va_arg(ap, double);
  va_end(ap);
  return tot;
}
