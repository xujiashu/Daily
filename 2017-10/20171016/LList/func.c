#include"Lhea.h"
static void CopyToNode(Item item, Node * node)
{
  node->item = item;
}

void InitList(List * plist)
{
  *plist = NULL;
}

bool IsEmpty(const List * plist)
{
  return *plist == NULL;
}

bool IsFull(const List * plist)
{
  Node * pt;
  bool full;
  pt = (Node *)malloc(sizeof(Node));
  if(pt == NULL)
    full = true;
  else
    full = false;
  free(pt);
  return full;
}

unsigned int ItemCount(const List * plist)
{
  unsigned int count = 0;
  Node * pnode;
  pnode = *plist;
  while(pnode != NULL)
  {
    count++;
    pnode = pnode->next;
  }
  return count;
}

bool AddItem(Item item, List * plist)
{
  Node * pnew;
  Node * pnode = *plist;

  pnew = (Node *)malloc(sizeof(Node));
  if(pnew == NULL)
    return false;
  CopyToNode(item, pnew);
  pnew->next = NULL;

  if(pnode == NULL)
    *plist = pnew;
  else
  {
    while(pnode->next != NULL)
      pnode = pnode->next;
    pnode->next = pnew;
  }
  return true;
}

void Traverse(const List * plist, void (* pfun)(Item item))
{
  Node * pnode = *plist;
  while(pnode != NULL)
  {
    (* pfun)(pnode->item);
    pnode = pnode->next;
  }
}

void EmptyList(List * plist)
{
  Node * pnode;
  while(*plist != NULL)
  {
    pnode = (*plist)->next;
    free(*plist);
    *plist = pnode;
  }
}
