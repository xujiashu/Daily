#include<stdio.h>
#include<stdlib.h>
#define CNTL_Z '\032'
#define SLEN 50

int main(int argc, char *argv[])
{
  char ch;
  FILE *fp;
  long count, last;

  if(argc<2)
  {
    fprintf(stderr, "Usage: %s filename.", argv[0]);
    exit(1);
  }
  if((fp=fopen(argv[1], "rb")) == NULL)
  {
    printf("can't open the %s", argv[1]);
    exit(2);
  }
  fseek(fp, 0L, SEEK_END);
  last = ftell(fp);
  for(1L; count<=last; count++)  //same result when init with 0L
  {
    fseek(fp, -count, SEEK_END);  //relative distance
    ch = getc(fp);
    if(ch!=CNTL_Z && ch!='\r' && ch!=EOF)
      putchar(ch);
/*    if(ch == '\r')  //for the Macintosh
      putchar('\n');
    else
      putchar(ch);  */
  }
//  putchar('\n');
  fclose(fp);

  return 0;
}

