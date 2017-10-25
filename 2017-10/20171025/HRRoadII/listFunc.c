#include"HRRoad.h"

static Tract initTract = {  //it would not be changed
    .posA = {-1, -1},
    .posB = {-1, -1},

    //x -> A -> D  //no B cause A include the A and B, when pick B, mark it with D
    .pick = 'x',  //pick A or D double picked or x not picked or X single picked
    .direc =  'Q'};  //u d l r or Q(up down left right and Q unreachable)

static void preDeal(Node * node)
{
  int i;
  for(i=0; i<8; i++)
    node->traList[i] = initTract;
}


static void CopyToNode(mapCode code, Node * node)
{
  node->graphc = code;
}


//status function
void InitList(Road road)
{
  road->head = NULL;
  road->rear = NULL;
  road->total = 0;
}

bool IsEmpty(const Road road)
{
  return road->total == 0;
}

bool IsFull(const Road road)
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



bool NextStep(mapCode code, Road road)   //add item
{
  Node * pnew;
  Node * pnode = road->head;

  pnew = (Node *)malloc(sizeof(Node));
  if(pnew == NULL)
    return false;
  preDeal(pnew);   //traList

  CopyToNode(code, pnew);  //mapcode
  pnew->next = NULL;  //next node

  if(pnode == NULL)  //empty
  {
    pnew->prenode = NULL;
    road->head = pnew;
    road->rear = pnew;
  }
  else  //not empty
  {
    road->rear->next = pnew;
    pnew->prenode = road->rear;
    road->rear = pnew;
  }

  (road->total)++;

  return true;
}


void EmptyList(Road road)
{
  Node * pnode;
  while(road->head != NULL)
  {
    pnode = (road->head)->next;
    free(road->head);
    road->head = pnode;
  }
}

void DropTail(Node * head)
{
  Node * pnode;
  while(head != NULL)
  {
    pnode = head->next;
    free(head);
    head = pnode;
  }
}

void Retreat(Road road)
{
  Node * pnode;

  if(IsEmpty(road))
  {
    fprintf(stderr, "unknown error!!!\n");  //I never see this error
    exit(1);
  }

  pnode = road->rear;
  road->rear = road->rear->prenode;

  if(road->rear != NULL)
    road->rear->next = NULL;

  free(pnode);
  (road->total)--;

}
