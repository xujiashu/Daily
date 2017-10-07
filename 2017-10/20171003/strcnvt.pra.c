#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  char number[30];
  char *end;
  long value;
  
  fputs("Enter a number (empty line to quit): \n", stdout);
  while(fgets(number, 30-1, stdin) && number[0] != '\n')
  {
    number[strlen(number)-1] = '\0';
    value = strtol(number, &end, 10);
    printf("value: %ld, stopped at %s (%d)\n", value, end, *end);
    value = strtol(number, &end, 16);
    printf("value: %ld, stopped at %s (%d)\n", value, end, *end);
    fputs("Next number: \n", stdout);
  }
  fputs("Bye!\n", stdout);

  return 0;
}
