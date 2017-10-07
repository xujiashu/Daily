#include<stdio.h>
#include<string.h>
#define SIZE 80
#define LIM 20
#define HALT " "

void stsrt(char *string[], int num);

int main()
{
  char input[LIM][SIZE];
  char *ptstr[LIM];  //contain LIM pointers
  int ct = 0;
  int k;

  printf("Input up to %d lines, and I will sort them.\n", LIM);
  printf("To stop, press the Enter key tat a line's start.\n");
  while(ct<LIM && 
  fgets(input[ct], SIZE-1, stdin)!=NULL && 
  input[ct][0] != '\n')
  {
    ptstr[ct] = input[ct];
    ct++;
  }
  stsrt(ptstr, ct);
  fputs("Here's the sorted list: \n", stdout);
  for(k=0; k<ct; k++)
    fputs(ptstr[k], stdout);

  return 0;
}

void stsrt(char *strings[], int num)
{
  char *temp;
  int top, seek;

  for(top=0; top<num-1; top++)
  {
    for(seek = top+1; seek<num; seek++)
      if(strcmp(strings[top], strings[seek]) > 0)
      {
        temp = strings[top];
	strings[top] = strings[seek];
	strings[seek] = temp;
      }
  }
}
