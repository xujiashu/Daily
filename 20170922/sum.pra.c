#include<stdio.h>
#define SIZE 10
int sump(int * start, int * end);
int main()
{
  int marbles[SIZE] = {20, 10, 11, 12, 16, 21, 9, 10, 18, 2};
  long answer;

  answer = sump(marbles, marbles + SIZE);
  printf("The total number of marbles is %ld.\n", answer);
  return 0;
}

int sump(int * start, int * end)
{
  int total = 0;
  while(start < end)
  {
    total += *start++;
//    total += *start;
//    start++;
  }
  return total;
}
