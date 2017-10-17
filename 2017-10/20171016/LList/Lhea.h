#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Film{
  char title[20];
  int rating;
}Item;

typedef struct Node{
  Item item;
  struct Node * next;
}Node;

typedef Node * List;

void InitList(List * plist);

bool IsEmpty(const List * plist);

bool IsFull(const List * plist);

unsigned int ItemCount(const List * plist);

bool AddItem(Item item, List * plist);

void Traverse(const List * plist, void (* pfun)(Item item));

void EmptyList(List * plist);

