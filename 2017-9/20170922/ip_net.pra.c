#include<stdio.h>
#define MAXN 1010

int ipAdd[MAXN][4];
/*
//Nothing to do with the program.
int meetz(int num)
{
  int i;
  int cpar = 128;
  for(i=0; i<=8; i++)
  {
    num = num << (i);
    if((num & cpar) == 0) return i;
  }
  return -1;
}

//The meetz test sample
int a, b, c;
a = 128;
b = 192;
c = 0;
printf("128:%d\n192:%d\n0:%d\n", meetz(a), meetz(b), meetz(c));
*/
int is_same(int poi[MAXN][4], int count, int n)
{
  int i;
  int sum=0;
  for(i=0; i<count; i++) sum += poi[i][n];
  if(sum == poi[0][n] * count) return 1;
  else return 0;
}
main()
{
  int n;
  int i;
  int k;
  int count=0;
  int poi[MAXN][4];
  int result = 255;
  int covery[4] = {0, 0, 0, 0};
  int minIp[4];
  for(n=0; n<MAXN; n++)
  {
    if(scanf("%d,%d,%d,%d",
    &poi[n][0], &poi[n][1], poi[n]+2, poi[n]+3) != 4) break;
    count++;
  }

  for(n=0; n<4; n++)
  {
    if(is_same(poi, count, n)) ;
    else
    {
      for(i=1; i<=8; i++)
      {
        result = result << 1;
        for(k=0; k<count; k++)
	{
	  poi[k][n] = poi[k][n] & result;
	}
	if(is_same(poi, count, n)) break;
      }
      for(k=0; k<n; k++)
      {
        covery[k] = 255;
      }
      covery[k] = result & 255;
    }
  }
  for(i=0; i<4; i++) minIp[i] = poi[0][i] & covery[i];
  printf("minIp:%d", minIp[0]);
  for(i=1; i<4; i++) printf(".%d", minIp[i]);
  printf("\n");

  printf("network:%d", covery[0]);
  for(i=1; i<4; i++) printf(".%d", covery[i]);
  printf("\n");
  
  return 0;
}
//Congratulation!
