#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct item
{
  char title[40];
  int rating;
}Item;

typedef struct node
{
  Item item;
  struct node * next;
}Node;

typedef struct myqueue
{
  Node * head;
  Node * rear;
  unsigned int sumn;
}myQueue;

typedef myQueue * Queue;

void InitList(Queue plist);
bool IsEmpty(const Queue plist);
bool IsFull(const Queue plist);
unsigned int ItemCount(const Queue plist);
bool AddItem(Item item, Queue plist);
void Traverse(const Queue plist, void (* pfun)(Item item));
void EmptyList(Queue plist);
bool DeItem(Item * pitem, Queue plist);
