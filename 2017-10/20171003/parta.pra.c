#include<stdio.h>
void callCount();
void accumulate(int);
int count = 0;
int main()
{
  int times;
  register int i;
  puts("Times 0 quit: ");
  while(scanf("%d", &times) == 1 && times)
  {
    ++count;
    for(i=times; i>=0; i--)
      accumulate(i);
    puts("Times 0 quit: ");
  }
  callCount();
  return 0;
  
}

void callCount()
{
  printf("count: %d\n", count);
}
