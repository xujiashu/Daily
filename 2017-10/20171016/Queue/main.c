#include <stdio.h>
#include <stdlib.h>
#include"qhea.h"
//#define AddAndDisp  //not define to test pop item.

void disp(Item);

int main()
{
  myQueue mymovies;
  Item themovie;
  Queue movies;

  movies = &mymovies;

  InitList(movies);
  puts("Enter the movie title: ");
  while(gets(themovie.title) != NULL && themovie.title[0] != '\0')
  {
    puts("Enter the rating: ");
    scanf("%d", &themovie.rating);
    while(getchar() != '\n')
      continue;
    AddItem(themovie, movies);
    puts("Enter the next movie(empty line to stop): ");
  }

#ifdef AddAndDisp
  if(IsEmpty(movies))
    puts("You enter no data.");
  else
  {
    puts("Here is the list: ");
    Traverse(movies, disp);
    printf("You enter %d movies. \n", ItemCount(movies));
    EmptyList(movies);
  }
  puts("Bye!");

#endif
#ifndef AddAndDisp
  Item item;
  if(IsEmpty(movies))
    puts("You enter no data.");
  else
  {
    puts("Pop the movies: ");
    while(DeItem(&item, movies))
      disp(item);
    printf("Now the Queue have %d movies. \n", ItemCount(movies));
    EmptyList(movies);
  }
  puts("Bye!");

#endif // AddAndDisp

  printf("Hello world!\n");
  return 0;
}

void disp(Item item)
{
  printf("Movie: %s Rating: %d\n", item.title, item.rating);
}
