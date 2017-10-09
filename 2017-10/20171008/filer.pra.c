#include<stdlib.h>
#include<stdio.h>
#define SIZE 20

int main(int argc, char *argv[])
{
  char string[SIZE];
  FILE *fp;
  int i;
  if(argc<2)
  {
    fprintf(stderr, "Usage: %s filename", argv[0]);
    exit(1);
  }
  if((fp=fopen(argv[1], "rb")) == NULL)
  {
    fprintf(stderr, "Can't open %s", argv[1]);
    exit(2);
  }
  fread(string, sizeof(char), SIZE, fp);
  fclose(fp);
  fputs(string, stdout);
  return 0;
}
