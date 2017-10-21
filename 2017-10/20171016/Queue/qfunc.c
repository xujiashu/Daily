#include"qhea.h"

static void CopyToNode(Item item, Node * node)
{
  memcpy(&node->item, &item, sizeof(Item));
}

static bool CopyToItem(Item * pitem, Node * node)
{
  if(node != NULL)
    memcpy(pitem, &node->item, sizeof(Item));
  else
    return false;
  return true;
}

void InitList(Queue plist)
{
  plist->head = NULL;
  plist->rear = NULL;
  plist->sumn = 0;
}

bool IsEmpty(const Queue plist)
{
  return plist->sumn == 0;
}

bool IsFull(const Queue plist)
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

unsigned int ItemCount(const Queue plist)
{
  return plist->sumn;
}

bool AddItem(Item item, Queue plist)
{
  Node * pnew;  //create a new Node{item, next}

  if(IsFull(plist))
    return false;

  pnew = (Node *)malloc(sizeof(Node));
  if(pnew == NULL)
  {
    fprintf(stderr, "Unable to allocate memory!\n");
    exit(1);
  }
  CopyToNode(item, pnew);
  pnew->next = NULL;

  if(IsEmpty(plist))
  {
    plist->head = pnew;
    plist->rear = pnew;
  }
  else
    plist->rear->next = pnew;
  plist->rear = pnew;
  plist->sumn++;

  return true;
}

void Traverse(const Queue plist, void (* pfun)(Item item))
{
  Node * pnode = plist->head;
  while(pnode != NULL)
  {
    (* pfun)(pnode->item);
    pnode = pnode->next;
  }
}

void EmptyList(Queue plist)
{
  Node * pnode;
  Node * ptl = plist->head;
  while(ptl != NULL)
  {
    pnode = ptl->next;
    free(ptl);
    ptl = pnode;
  }
  plist->rear = NULL;
}

bool DeItem(Item * pitem, Queue plist)
{
  Node * pnode;
  if(IsEmpty(plist))
    return false;

  CopyToItem(pitem, plist->head);
  pnode = plist->head;
  plist->head = plist->head->next;
  free(pnode);
  plist->sumn--;
  if(plist->sumn == 0)
    plist->rear = NULL;

  return true;
}
