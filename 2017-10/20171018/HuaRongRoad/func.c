#include"huarongd.h"
#include<stdio.h>
#include<string.h>

#define BADNUM(x) ((x)==2 || (x)==3 || (x)==6 || (x)==0)

static char seeds[8] = {'u', 'd', 'l', 'r', 'u', 'd', 'l', 'r'};

static bool isLoop(Road road, mapCode code)
{
  Node * pnode = road->head;
  while(pnode != road->rear)
  {
    if(pnode->graphc.codea == code.codea &&
       pnode->graphc.codeb == code.codeb)
       return true;
    pnode = pnode->next;
  }
  return false;
}

extern int PointA[2][5];
extern int PointB[2][5];

static Tract tractModel = {   //this will change: for read posit data
    .posA = {-1, -1},
    .posB = {-1, -1},
    .pick = 'x',
    .direc =  'Q'};


static int currGraph[4][5];

static void getPosit(void)
{
  bool flag = true;
  int i, j;
  for(i=0; i<4; i++)
    for(j=0; j<5; j++)
      if(currGraph[i][j] == 0)
      {
          if(flag)
        {
          tractModel.posA.i = i;
          tractModel.posA.j = j;
          flag = false;
        }
        else
        {
          tractModel.posB.i = i;
          tractModel.posB.j = j;
        }
      }
}

static void findWays(Tract * tractList)
{
  int i;
  for(i=0; i<8; i++)
  {
    tractModel.direc = seeds[i];
    tractList[i] = tractModel;
  }
}

static bool boundaryCheck(int i,int j, char direc)
{
  switch(direc)
  {
  case 'u':
    if(RISGOOD(i-1))
      ;
    else
      return false;
    break;
  case 'd':
    if(RISGOOD(i+1))
      ;
    else
      return false;
    break;
  case 'l':
    if(CISGOOD(j-1))
      ;
    else
      return false;
    break;
  case 'r':
    if(CISGOOD(j+1))
      ;
    else
      return false;
    break;
  }

  return true;
}


void codeToGraph(const mapCode * code, int (*HRR)[5])
{
  int i, j;
  int bit = 0;
  for(i=0; i<4; i++)
    if(i<2)
      for(j=0; j<5; j++)
      {
        bit = 3*(9-5*i-j);
        HRR[i][j] = (code->codea & PointA[i][j]) >> bit;
      }
    else
      for(j=0; j<5; j++)
      {
        bit = 3*(9-5*(i-2)-j);
        HRR[i][j] = (code->codeb & PointB[i-2][j]) >> bit;
      }
}

void graphToCode(mapCode * code, int (*HRR)[5])
{
  int i, j;
  int role;
  int bit = 0;
  for(i=0; i<4; i++)
    if(i<2)
      for(j=0; j<5; j++)
      {
        bit = 3*(9-5*i-j);
        role = HRR[i][j];
        role <<= bit;
        code->codea = code->codea&(~PointA[i][j]);
        code->codea += role;
      }
    else
      for(j=0; j<5; j++)
      {
        bit = 3*(9-5*(i-2)-j);
        role = HRR[i][j];
        role <<= bit;
        code->codeb = code->codeb&(~PointB[i-2][j]);
        code->codeb += role;
      }
}
/*
Tract pickaWay(mapCode code, int seed)
{
  Tract Action = {
    .posA = {-1,-1},
    .posB = {-1,-1},
    .direc = 'Q',
    .pick = 'x'
  };    //start status

  if(seeds[seed] == 'A')
    Action.pick = 'A';
  else if(seeds[seed] == 'B')
    Action.pick = 'B';

  Action.direc = seeds[16-seed];
  Action.posA = code.posA;
  Action.posB = code.posB;

  return Action;
}
*/

//I don't want to see this code again.......
//pick a way and then try to move.
bool moveRole(Road road, char direc, int seed)  //change the current graph
{
  Node * pnode = road->rear;
//  memcpy(pnode, road->rear, sizeof(road->rear));
  int p1i, p1j;
  int p2i, p2j;
  int sgi, sgj;  //single point
  int mead1, mead2;  //to exchange value

  //read data
  p1i = pnode->traList[seed].posA.i;
  p1j = pnode->traList[seed].posA.j;
  p2i = pnode->traList[seed].posB.i;
  p2j = pnode->traList[seed].posB.j;

  sgi = seed<4 ? p1i : p2i;
  sgj = seed<4 ? p1j : p2j;

  //x move single D move double
  if(pnode->traList[seed].pick == 'x')
  {
    if(boundaryCheck(sgi, sgj, direc))
    {
      switch(direc)
      {

      case 'u':
        if(BADNUM(currGraph[sgi-1][sgj]))
        {
          road->rear->traList[seed].pick = 'A';
          return false;
        }
        else if(currGraph[sgi-1][sgj] == 5)
        {
          currGraph[sgi-2][sgj] = 0;
          currGraph[sgi-1][sgj] = 4;
          currGraph[sgi][sgj] = 5;
        }
        else if(currGraph[sgi-1][sgj] == 1)
        {
          currGraph[sgi-1][sgj] = 0;
          currGraph[sgi][sgj] = 1;
        }
        break;
      case 'd':
        if(BADNUM(currGraph[sgi+1][sgj]))
        {
          road->rear->traList[seed].pick = 'A';
          return false;
        }
        else if(currGraph[sgi+1][sgj] == 4)
        {
          currGraph[sgi+2][sgj] = 0;
          currGraph[sgi+1][sgj] = 5;
          currGraph[sgi][sgj] = 4;
        }
        else if(currGraph[sgi+1][sgj] == 1)
        {
          currGraph[sgi+1][sgj] = 0;
          currGraph[sgi][sgj] = 1;
        }
        break;

      case 'l':
        if(BADNUM(currGraph[sgi][sgj-1]))
        {
          road->rear->traList[seed].pick = 'A';
          return false;
        }
        else if(currGraph[sgi][sgj-1] == 2)
        {
          currGraph[sgi][sgj-2] = 0;
          currGraph[sgi][sgj-1] = 3;
          currGraph[sgi][sgj] = 2;
        }
        else if(currGraph[sgi][sgj-1] == 1)
        {
          currGraph[sgi][sgj-1] = 0;
          currGraph[sgi][sgj] = 1;
        }
        break;

      case 'r':
        if(BADNUM(currGraph[sgi][sgj+1]))
        {
          road->rear->traList[seed].pick = 'A';
          return false;
        }
        else if(currGraph[sgi][sgj+1] == 3)
        {
          currGraph[sgi][sgj+2] = 0;
          currGraph[sgi][sgj+1] = 2;
          currGraph[sgi][sgj] = 3;
        }
        else if(currGraph[sgi][sgj+1] == 1)
        {
          currGraph[sgi][sgj+1] = 0;
          currGraph[sgi][sgj] = 1;
        }
        break;
      }
      road->rear->traList[seed].pick = 'A';
    }
    else
    {
      road->rear->traList[seed].pick = 'A';
      return false;
    }

    return true;
  }

  else if(pnode->traList[seed].pick == 'A' && seed<4)
  {
    if(ISNEIGHBOR(p1i+p1j, p2i+p2j) == 1 &&
       boundaryCheck(p1i, p1j, direc) &&
       boundaryCheck(p2i, p2j, direc)
       )
    {
      switch(direc)
      {
      case 'u':
        if(ISNEIGHBOR(p1j, p2j) != 1)
        {
          road->rear->traList[seed].pick = 'Q';
          return false;
        }
        if(p1i == p2i)
        {
          mead1 = p1j<p2j ? p1j : p2j;
          mead2 = p1j>p2j ? p1j : p2j;
          if(currGraph[p1i-1][mead1] == 3 && currGraph[p2i-1][mead2] == 2) //p1i equal to p2i
          {
            currGraph[p1i][mead1] = 3;
            currGraph[p2i][mead2] = 2;
            currGraph[p1i-1][mead1] = 0;
            currGraph[p2i-1][mead2] = 0;
          }
          else if(currGraph[p1i-1][mead1] == 6 && currGraph[p2i-1][mead2] == 6)
          {
            currGraph[p1i][mead1] = 6;
            currGraph[p2i][mead2] = 6;
            currGraph[p1i-2][mead1] = 0;
            currGraph[p2i-2][mead2] = 0;
          }
          else
          {
            road->rear->traList[seed].pick = 'Q';
            return false;
          }
        }
        else
        {
          road->rear->traList[seed].pick = 'Q';
          return false;
        }
        break;

      case 'd':
        if(ISNEIGHBOR(p1j, p2j) != 1)
        {
          road->rear->traList[seed].pick = 'Q';
          return false;
        }
        if(p1i == p2i)
        {
          mead1 = p1j<p2j ? p1j : p2j;
          mead2 = p1j>p2j ? p1j : p2j;
          if(currGraph[p1i+1][mead1] == 3 && currGraph[p2i+1][mead2] == 2) //p1i equal to p2i
          {
            currGraph[p1i][mead1] = 3;
            currGraph[p2i][mead2] = 2;
            currGraph[p1i+1][mead1] = 0;
            currGraph[p2i+1][mead2] = 0;
          }
          else if(currGraph[p1i+1][mead1] == 6 && currGraph[p2i+1][mead2] == 6)
          {
            currGraph[p1i][mead1] = 6;
            currGraph[p2i][mead2] = 6;
            currGraph[p1i+2][mead1] = 0;
            currGraph[p2i+2][mead2] = 0;
          }
          else
          {
            road->rear->traList[seed].pick = 'Q';
            return false;
          }
        }
        else
        {
          road->rear->traList[seed].pick = 'Q';
          return false;
        }
        break;

      case 'l':
        if(ISNEIGHBOR(p1i, p2i) != 1)
        {
          road->rear->traList[seed].pick = 'Q';
          return false;
        }
        if(p1j == p2j)
        {
          mead1 = p1i<p2i ? p1i : p2i;
          mead2 = p1i>p2i ? p1i : p2i;
          if(currGraph[mead1][p1j-1] == 4 && currGraph[mead2][p2j-1] == 5) //p1i equal to p2i
          {
            currGraph[mead1][p1j] = 4;
            currGraph[mead2][p2j] = 5;
            currGraph[mead1][p1j-1] = 0;
            currGraph[mead2][p2j-1] = 0;
          }
          else if(currGraph[mead1][p1j-1] == 6 && currGraph[mead2][p2j-1] == 6)
          {
            currGraph[mead1][p1j] = 6;
            currGraph[mead2][p2j] = 6;
            currGraph[mead1][p1j-2] = 0;
            currGraph[mead2][p2j-2] = 0;
          }
          else
          {
            road->rear->traList[seed].pick = 'Q';
            return false;
          }
        }
        else
        {
          road->rear->traList[seed].pick = 'Q';
          return false;
        }
        break;

      case 'r':
        if(ISNEIGHBOR(p1i, p2i) != 1)
        {
          road->rear->traList[seed].pick = 'Q';
          return false;
        }
        if(p1j == p2j)
        {
          mead1 = p1i<p2i ? p1i : p2i;
          mead2 = p1i>p2i ? p1i : p2i;
          if(currGraph[mead1][p1j+1] == 4 && currGraph[mead2][p2j+1] == 5) //p1i equal to p2i
          {
            currGraph[mead1][p1j] = 4;
            currGraph[mead2][p2j] = 5;
            currGraph[mead1][p1j+1] = 0;
            currGraph[mead2][p2j+1] = 0;
          }
          else if(currGraph[mead1][p1j+1] == 6 && currGraph[mead2][p2j+1] == 6)
          {
            currGraph[mead1][p1j] = 6;
            currGraph[mead2][p2j] = 6;
            currGraph[mead1][p1j+2] = 0;
            currGraph[mead2][p2j+2] = 0;
          }
          else
          {
            road->rear->traList[seed].pick = 'Q';
            return false;
          }
        }
        else
        {
          road->rear->traList[seed].pick = 'Q';
          return false;
        }
        break;
      }

      road->rear->traList[seed].pick = 'Q';

      }

      else
      {
        road->rear->traList[seed].pick = 'Q';
        return false;
      }
  }

  else
  {
    road->rear->traList[seed].pick = 'Q';
    return false;
  }

  return true;
}


bool goForward(Road road)  //first call function
{
  //the main data is mapCode and the traList.
  Node * pnode;
  pnode = road->rear;

  mapCode currCode;
  int i;
  char pick;
  codeToGraph(&(pnode->graphc), currGraph);  //load graph  -cg1
  i = pnode->traList[0].posA.i;
  if(i == 65535)  //is new graph
  {
    //init the traLizt
    getPosit();
    findWays(pnode->traList);  //find ways for the new graph  -tl1
  }

  for(i=0; i<8; i++) //A:0-3, B:4-7 : pick a Way get the seed
  {
    pick = pnode->traList[i].pick;  //the way did not go to
    if(pick != 'Q')
      break;
  }

  if(moveRole(road, pnode->traList[i].direc, i))  //current graph had changed.  -cg2  traList changed too -tl2
  {
    graphToCode(&currCode, currGraph);  //encode
    if(isLoop(road, currCode) == false)  //success move and not a loop
    {
      NextStep(currCode, road);
    }
    else
      return true;  //quit this try
  }
  else if(i == 8)  //fail to move and there is no way
    return false;

  return true;  //continue move
}


bool isFlee(void)
{
  if(currGraph[1][0] == 6 && currGraph[2][0] == 6)
    return true;
  else
    return false;
}


void disp(Road road)
{
  Node * pnode = road->head;
  int hrrgraph[4][5];
  int i, j;
  puts("----------");
  while(pnode != NULL)
  {
    codeToGraph(&(pnode->graphc), hrrgraph);
    for(i=0; i<4; i++)
    {
      for(j=0; j<5; j++)
        printf("%d ",hrrgraph[i][j]);

      putchar('\n');
    }
    printf("\n-----------\n");
    pnode = pnode->next;
  }
}
