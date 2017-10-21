#include"huarongd.h"

static Tract initTract = {
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

void InitList(Road road)
{
  road->head = NULL;
  road->rear = NULL;
}

bool IsEmpty(const Road road)
{
  return road->head == NULL;
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

unsigned int StepCount(const Road road)
{
  unsigned int count = 0;
  Node * pnode;
  pnode = road->head;
  while(pnode != NULL)
  {
    count++;
    pnode = pnode->next;
  }
  return count;
}

bool NextStep(mapCode code, Road road)
{
  Node * pnew;
  Node * pnode = road->head;

  pnew = (Node *)malloc(sizeof(Node));
  if(pnew == NULL)
    return false;
  preDeal(pnew);

  CopyToNode(code, pnew);
  pnew->next = NULL;

  if(pnode == NULL)
  {
    road->head = pnew;
    road->rear = pnew;
  }
  else
  {
   road->rear->next = pnew;
   pnew->prenode = road->rear;
  }
  road->rear = pnew;

  return true;
}

void Traverse(const Road road, void (* pfun)(mapCode code))
{
  Node * pnode = road->head;
  while(pnode != NULL)
  {
    (* pfun)(pnode->graphc);
    pnode = pnode->next;
  }
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

void Retreat(Road road)
{
  Node * pnode;
  if(IsEmpty(road))
  {
    fprintf(stderr, "unknown error!!!\n");
    exit(1);
  }

  pnode = road->rear;
  road->rear = road->rear->prenode;
  free(pnode);

}
