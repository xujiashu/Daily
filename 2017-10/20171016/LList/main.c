#include <stdio.h>
#include <stdlib.h>
#include "Lhea.h"

void showmovies(Item item);

int main()
{
  List movies;
  Item temp;
  InitList(&movies);
  if(IsFull(&movies))
  {
    fprintf(stderr, "No memory available!\n");
    exit(1);
  }

  puts("Enter the movie title: ");
  while(gets(temp.title) != NULL && temp.title[0] != '\0')
  {
    puts("Enter your rating <0-10>: ");
    scanf("%d", &temp.rating);
    while(getchar() != '\n')
      continue;
    if(AddItem(temp, &movies) == false)
    {
      fprintf(stderr, "Problem allocating memory\n");
      break;
    }
    if(IsFull(&movies))
    {
      puts("The list is full.");
      break;
    }
    puts("Enter next movie title (empty line to stop): ");
  }
  if(IsEmpty(&movies))
    printf("No data entered. \n");
  else
  {
    puts("Here is the movie list: ");
    Traverse(&movies, showmovies);
  }
  printf("You entered %d movies. \n", ItemCount(&movies));
  EmptyList(&movies);
  puts("Bye!");
  return 0;
}

void showmovies(Item item)
{
  printf("Movie: %s Rating: %d\n", item.title, item.rating);
}

