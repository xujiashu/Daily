#include<stdio.h>
#include<string.h>

int main()
{
  int a[5][5];
  int cp[5][5];
  memset(a, 0, sizeof(a));
  memcpy(cp, a, sizeof(a));
  int i, j;
  for(i=0; i<5; i++)
  {
    for(j=0; j<5; j++) printf("%d", a[i][j]);
    printf("\n");
  }

  printf("|||||||||\n");

  for(i=0; i<5; i++)
  {
    for(j=0; j<5; j++) printf("%d", cp[i][j]);
    printf("\n");
  }

  return 0;
}

