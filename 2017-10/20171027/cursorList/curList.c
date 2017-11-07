#include"curList.h"
#include<string.h>

static Position
CursorAlloc(void)
{
  Position p;
  p = CursorSpace[0].Next;
  CursorSpace[0].Next = CursorSpace[p].Next;

  return p;
}

static void
CursorFree(Position p)
{
  CursorSpace[p].Next = (CursorSpace[0]).Next;
  CursorSpace[0].Next = p;
}

int
IsEmpty(const List L)
{
  return CursorSpace[L].Next == 0;
}

int
IsLast(Position p, const List L)
{
  return CursorSpace[p].Next == 0;
}

Position
Find(char * X, const List L)
{
  Position p;
  p = CursorSpace[L].Next;
  while(p && strcmp(CursorSpace[p].Element, X) != 0)
    p = CursorSpace[p].Next;
  return p;
}

Position
FindPrevious(char * X, const List L)
{
  Position p;
  p = L;
  while(CursorSpace[p].Next &&
        strcmp(CursorSpace[CursorSpace[p].Next].Element , X) != 0)
    p = CursorSpace[p].Next;
  return p;
}

void
Delete(char * X, List L)
{
  Position p, tmpCell;
  p = FindPrevious(X, L);
  if(!IsLast(p, L))
  {
    tmpCell = CursorSpace[p].Next;
    CursorSpace[p].Next = CursorSpace[tmpCell].Next;
    CursorFree(tmpCell);
  }

}

void  //Insert after legal position p
Insert(char * X, List L, Position p)
{
  Position tmpcell;
  tmpcell = CursorAlloc();
  if(tmpcell == 0)
    fprintf(stderr, "Out of space!!");

  strcpy(CursorSpace[tmpcell].Element, X);
  CursorSpace[tmpcell].Next = CursorSpace[p].Next;
  CursorSpace[p].Next = tmpcell;
}

void
InitList(void)
{
  int i;
  for(i=0; i<SpaceSize-1; i++)
    CursorSpace[i].Next = i+1;
  CursorSpace[i].Next = 0;
}

void
MakeEmpty(List L)
{
  Position p, tmp;

  p = CursorSpace[L].Next;
  CursorSpace[L].Next = 0;
  while(p != 0)
  {
    tmp = CursorSpace[p].Next;
    CursorFree(p);
    p = tmp;
  }
}

void
PrintList(const List L)
{
  Position p;
  p = CursorSpace[L].Next;
  while(p != 0)
  {
    printf("Position %d: %s\n",p ,CursorSpace[p].Element);
    p = CursorSpace[p].Next;
  }
}

List
CreateList(void)
{
  List L;
  L = CursorAlloc();
  CursorSpace[L].Next = 0;
  return L;
}

static Position
FindLast(List L)
{
  Position p;
  p = L;
  while(CursorSpace[p].Next != 0)
    p = CursorSpace[p].Next;
  return p;
}

void
AddName(char * X, List L)
{
  Position p;
  p = FindLast(L);
  Insert(X, L, p);
}











