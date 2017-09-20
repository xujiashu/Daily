#include<stdio.h>
#include<string.h>
#define MAXN 100
#define LEN 6

int comList[6][4] = {{1,2,4,3},{5,2,0,3},{5,4,0,1},{5,1,0,4},{5,3,0,2},{1,3,4,2}};

int compare(const char *strm, const char *strc, int n)
{
  //default n is 6.
  //degitList is a global val.
  char comp[MAXN];
  int i;
  int init[6] = {0, 5, 1, 2, 4, 3};
  int list[4];
  int k;
  int listLen = 4;
  int flag;
  int t;
  int index;
  int j;
  for(i=0; i<n; i++) comp[i] = *(strm + init[i]);//ok
  for(j=0; j<n; j++)
  {
    if(comp[0]==*(strc+j) && comp[1]==*(strc+(n-1-j)))
    {
      memcpy(list, comList[j], sizeof(comList[j]));
      for(k=0; k<listLen; k++)
      {
        for(t=0; t<listLen; t++)
        {
          flag = 1;
	  index = (t+k)%listLen;  //ok
	  if(*(strc+list[index]) != comp[2+t])
	  {
	    flag = 0;
	    break;
	  }
        }
        if(flag) return 1;
      }
    }
  }
  return 0;
}

int main()
{
  char strm[LEN];
  char strc[LEN];
  printf("first:\n");
  scanf("%s", strm);
  printf("second:\n");
  scanf("%s", strc);
  if(compare(strm, strc, LEN)) printf("Yes\n");
  else printf("No\n");
  return 0;
}
//Yes! I make it!
//Though it is urgly!
