#define SpaceSize (100)
#include<stdio.h>



struct Node
{
  char Element[20];
  int Next;
};

struct Node CursorSpace[SpaceSize];

typedef int Position;
typedef Position List;


int IsEmpty(const List L);

int IsLast(const Position p, List L);


Position Find(char * X, const List L);

Position FindPrevious(char * X, const List L);


void Delete(char * X, List L);

void Insert(char * X, List L, Position p);


void InitList(void);

void  PrintList(const List L);

List CreateList(void);

void MakeEmpty(List L);

void AddName(char * X, List L);
