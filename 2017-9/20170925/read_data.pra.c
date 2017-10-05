#include<stdio.h>
//#define LOCAL
#define INF 1000000000

main()
{
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int num;
  scanf("%d", &num);
  printf("num:%d\n", num);
#endif
  FILE *fin, *fout;
  fin = fopen("input.txt", "rb");
  fout = fopen("output.txt", "wb");
  int x,n,s = 0;
  int min = INF;
  int max = -INF;
  while(fscanf(fin, "%d", &x) == 1)
  {
    s += x;
    if(x<min) min = x;
    if(x>max) max = x;
    n++;
  }
  fprintf(fout, "%d %d %.3f\n", min, max, (double)s/n);

  fclose(fin);
  fclose(fout);

  return 0;
}
