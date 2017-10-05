#include<stdio.h>
#define M 20
#define N 30
#define LOCAL

void mysort(int *list, int num)
{
  int i,j;
  for(i=0; i<num-1; i++)
  {
    for(j=i+1; j<num; j++)
    {
      int k;
      if(list[j] > list[i])
      {
        k = list[i];
	list[i] = list[j];
	list[j] = k;
      }
    }
  }
}


int main()
{
#ifdef LOCAL
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
#endif
  int S = M*N;
  int hight[S];
  int Vwater;
  int Vmax;
  int i = 0;
  while(i<S && scanf("%d", hight+i) == 1) i++;
  scanf("%d", &Vwater);
  mysort(hight, S);
//  for(i=0; i<M*N; i++) printf("%d", hight[i]);
  
  int Vstotal = 0;
  int result=0;
  float flood;
  for(i=0; i<S; i++) Vstotal += hight[i];
  
//  printf("Vwater: %d\n", Vwater);
  if(Vwater > 0)
  {
    for(i=1; i<S; i++)
    {
      Vstotal -= hight[i-1];
      if(hight[i] != hight[i-1])
      {
        Vmax = hight[i-1] * (S-i) * 10;
        if(Vwater + Vstotal*10 > Vmax)
        {
          result = S - i;
          break;
        }
      }
    }
  }
  else flood = 0.0;

  if(i == S) flood = 1.0;
  else flood = (float)result/S;
  printf("%.2f\%\n", flood*100);
  return 0;
}
