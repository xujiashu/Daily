#include <stdio.h>
#include <stdlib.h>
#include"curList.h"
#include<string.h>
#define TESTAD  //add and delete
//#define TESTAP  //add and print


#ifdef TESTAD
void Remove(List);
void Search(List);
void Add(List);
void Action(char, List);
#endif // TESTAD



int main()
{
#ifdef TESTAP
  List L1, L2;
  InitList();
  L1 = CreateList();
  L2 = CreateList();
  char Name[20];

  puts("Name(L1): ");

  while(gets(Name) != NULL && Name[0] != '\0')
  {
    AddName(Name, L1);
    puts("Next name(L1): ");
  }

  puts("Name(L2): ");
  while(gets(Name) != NULL && Name[0] != '\0')
  {
    AddName(Name, L2);
    puts("Next name(L2): ");
  }

  PrintList(L1);
  MakeEmpty(L1);
  PrintList(L2);
  MakeEmpty(L2);
#endif

#ifdef TESTAD
  List Lad;
  InitList();
  Lad = CreateList();
  char Name[20];
  char choice;


  puts("Name(Lad): ");

  while(gets(Name) != NULL && Name[0] != '\0')
  {
    AddName(Name, Lad);
    puts("Next name(Lad): ");
  }

  while(1)
  {
    printf("menu: s(search name)  a(add name)\n      r(remove name)  p(print List)\n      q(quit)\n");
    choice = getchar();
    while(getchar() != '\n')
      continue;
    Action(choice, Lad);
  }



#endif // TESTAD


  printf("Hello world!\n");
  return 0;
}



#ifdef TESTAD

void Search(List L)
{
  char Name[20];
  puts("Name(Lad): ");

  while(gets(Name) != NULL && Name[0] != '\0')
  {
    printf("%s: %d\n", Name, Find(Name, L));
    puts("Next name(Lad, empty line to quit): ");
  }
  while(getchar()!='\n')
    continue;
}

void Remove(List L)
{
  char Name[20];
  puts("Name(Lad): ");

  while(gets(Name) != NULL && Name[0] != '\0')
  {
    Delete(Name, L);
    puts("Next name(Lad, empty line to quit): ");
  }
  while(getchar()!='\n')
    continue;
}

void Add(List L)
{
  char Name[20];
  puts("Name(Lad): ");

  while(gets(Name) != NULL && Name[0] != '\0')
  {
    AddName(Name, L);
    puts("Next name(Lad, empty line to quit): ");
  }
  while(getchar()!='\n')
    continue;
}

void Action(char choice, List L)
{
  switch(choice)
  {
  case 's':
    Search(L);
    break;
  case 'r':
    Remove(L);
    break;
  case 'a':
    Add(L);
    break;
  case 'p':
    PrintList(L);
    break;
  case 'q':
    exit(1);
    break;
  default :
    PrintList(L);
  }
}

#endif // TESTAD

