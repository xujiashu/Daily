#include<stdio.h>
#include<string.h>
#define LINELEN 81
#define SIZE 40
#define LIM 5
#define TARGSIZE 7

int main()
{
  //init string.
  const char m1[40] = "Limit yourself to one lise's worth.";
  const char m2[] = "If you can't think of anything, fake it.";
  char name1[2+5] = {'1','2','3','4','5','6','\0'};
  char name2[LINELEN];
  const char *m3 = "\nEnough about me- What's your name? 1";//++m3 valid
  char m4[] = "\nEnough about me- What's your name? 2";//++m4 invalid
  
  char heart[] =  "I love you.1\n";//const address
  char *head = "I don't love you.2\n";//variable address

  while(*(head) != '\n')//sth interesting will happen when you
    putchar(*(head++)); //delete the character-'\n' in the head.
  putchar('\n');
  //while(*head) putchar(*(head++));

  //head[0] = 'c'; invalid
  //head=heart is valid while heart=head is invalid
  //similar to x=4 and 4=x
  
  const char *head2 = "I don't love you.3";//it's better to use const
  //string array
  const char *mytal[LIM] = {
  "Adding numbers swiftly",
  "Multiping accurately",
  "Stashing data",
  "Following instructions to the letter",
  "Understanding the C language"
  };

/*
  printf("%p\n", "we");
  printf("%p\n", "we");  //same address.
  printf("%p\n", "we are friends");  //different address.
*/

  //copy string
  char qwords[LIM][TARGSIZE];
  char temp[SIZE];
  int i = 0;
  
  printf("Enter %d words beginning with q: \n", LIM);
  while(i<LIM && gets(temp))
  {
   if(temp[0] != 'q')
     printf("%s doesn't begin with q!\n", temp);
   else
   {
     strncpy(qwords[i], temp, TARGSIZE-1);
     qwords[i][TARGSIZE-1] = '\0';
     i++;
   }
  }
  puts("Here are the words accepted: ");
  for(i=0; i<LIM; i++)
    puts(qwords[i]);

  return 0;
}

