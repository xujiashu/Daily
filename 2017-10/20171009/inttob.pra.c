#include<stdio.h>
char * itobs(int, char *);
void disp(const char *);

int main()
{
  int num;
  char numb[8*sizeof(int) + 1];
  puts("enter a number: ");
  while(scanf("%d", &num) == 1)
  {
    itobs(num, numb);
    printf("%d is \n", num);
    disp(numb);
    putchar('\n');

  }
  puts("Bye!");

  return 0;
}

char * itobs(int num, char * numb)
{
  int i;
  static int size = 8 * sizeof(int);    //run one time.
  for(i=size-1; i>=0; i--, num>>=1)
    numb[i] = (01&num) + '0';
  numb[size] = '\0';
  
  return numb;
}

void disp(const char * numb)
{
  int i;
  i = 0;
  while(numb[i])
  {
    putchar(numb[i]);
    if(++i%4 == 0 && numb[i])
      putchar(' ');
  }
}
