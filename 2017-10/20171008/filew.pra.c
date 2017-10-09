#include<stdlib.h>
#include<stdio.h>
#define SIZE 20

int main(int argc, char *argv[])
{
  FILE *fp;
  char string[SIZE] = "hello world!";
  if(argc<2)
  {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(1);
  }
  if((fp = fopen(argv[1], "wb")) == NULL)
  {
    fprintf(stderr, "Can't open %s", argv[1]);
    exit(2);
  }
  fwrite(string, sizeof(char), SIZE, fp);
  fclose(fp);

  return 0;
}
