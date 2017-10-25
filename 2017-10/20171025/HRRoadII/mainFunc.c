#include"HRRoad.h"
#include<stdio.h>
#include<string.h>

#define BADNUMUD(x) ((x)==2 || (x)==3 || (x)==6 || (x)==0)
#define BADNUMLR(x) ((x)==4 || (x)==5 || (x)==6 || (x)==0)

static char seeds[8] = {'u', 'd', 'l', 'r', 'u', 'd', 'l', 'r'};


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


//I don't want to see this code again.......
//pick a way and then try to move.

//check the choice reachable.
static bool moveRole(Node * pnode, char direc, int seed)  //change the current graph
{

  codeToGraph(&(pnode->graphc), currGraph);
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

  //you would not care the problem of (posA, posB) (posB, posA)
  //cause the getPosit() make sure posA.i<posB.i
  if(seed<4)
  {
    sgi = p1i;
    sgj = p1j;
  }
  else
  {
    sgi = p2i;
    sgj = p2j;
  }

  //x move one step each time and A move double
  if(pnode->traList[seed].pick == 'x')
  {
    if(boundaryCheck(sgi, sgj, direc))  //basically check
    {
      switch(direc)
      {


      //BADNUMUD(x) ((x)==2 || (x)==3 || (x)==6 || (x)==0)
      //BADNUMLR(x) ((x)==4 || (x)==5 || (x)==6 || (x)==0)
      //RISGOOD(x) ((x)>=0 && (x) < 4)  //i
      //CISGOOD(x) ((x)>=0 && (x) <5)  //j
      case 'u':
        if(BADNUMUD(currGraph[sgi-1][sgj]))  //0 2 3 6
        {
          pnode->traList[seed].pick = 'A';
          return false;
        }
        else if(currGraph[sgi-1][sgj] == 5 && RISGOOD(sgi-2))//0 2 3 5 6
        {
          currGraph[sgi-2][sgj] = 0;
          currGraph[sgi-1][sgj] = 4;
          currGraph[sgi][sgj] = 5;
        }
        else if(currGraph[sgi-1][sgj] == 1 && RISGOOD(sgi-1))//0 1 2 3 5 6 OK
        {
          currGraph[sgi-1][sgj] = 0;
          currGraph[sgi][sgj] = 1;
        }
        else  //4          0 1 2 3 4 5 6 should not meet 4 here.
        {
          fprintf(stderr, "Move wrong!");
          exit(1);
        }
        break;
      case 'd':
        if(BADNUMUD(currGraph[sgi+1][sgj]))  //0 2 3 6
        {
          pnode->traList[seed].pick = 'A';
          return false;
        }
        else if(currGraph[sgi+1][sgj] == 4 && RISGOOD(sgi+2))//0 2 3 4 6
        {
          currGraph[sgi+2][sgj] = 0;
          currGraph[sgi+1][sgj] = 5;
          currGraph[sgi][sgj] = 4;
        }
        else if(currGraph[sgi+1][sgj] == 1 && RISGOOD(sgi+1))//0 1 2 3 4 6
        {
          currGraph[sgi+1][sgj] = 0;
          currGraph[sgi][sgj] = 1;
        }
        else  //5             0 1 2 3 4 5 6 same reason
        {
          fprintf(stderr, "Move wrong");
          exit(1);
        }
        break;

      case 'l':
        if(BADNUMLR(currGraph[sgi][sgj-1]))  //0 4 5 6
        {
          pnode->traList[seed].pick = 'A';
          return false;
        }
        else if(currGraph[sgi][sgj-1] == 2 && CISGOOD(sgj-2))//0 2 4 5 6
        {
          currGraph[sgi][sgj-2] = 0;
          currGraph[sgi][sgj-1] = 3;
          currGraph[sgi][sgj] = 2;
        }
        else if(currGraph[sgi][sgj-1] == 1 && CISGOOD(sgj-1)) //0 1 2 4 5 6
        {
          currGraph[sgi][sgj-1] = 0;
          currGraph[sgi][sgj] = 1;
        }
        else  //3             0 1 2 3 4 5 6 same reason
        {
          fprintf(stderr, "Move wrong");
          exit(1);
        }
        break;

      case 'r':
        if(BADNUMLR(currGraph[sgi][sgj+1]))  //0 4 5 6
        {
          pnode->traList[seed].pick = 'A';
          return false;
        }
        else if(currGraph[sgi][sgj+1] == 3 && CISGOOD(sgj+2))//0 3 4 5 6
        {
          currGraph[sgi][sgj+2] = 0;
          currGraph[sgi][sgj+1] = 2;
          currGraph[sgi][sgj] = 3;
        }
        else if(currGraph[sgi][sgj+1] == 1 && CISGOOD(sgj+1))//0 1 3 4 5 6
        {
          currGraph[sgi][sgj+1] = 0;
          currGraph[sgi][sgj] = 1;
        }
        else  //2             0 1 2 3 4 5 6 same reason
        {
          fprintf(stderr, "Move wrong");
          exit(1);
        }
        break;
      }
      pnode->traList[seed].pick = 'A';
    }
    else
    {
      pnode->traList[seed].pick = 'A';
      return false;
    }

    return true;
  }

  else if(pnode->traList[seed].pick == 'A' && seed<4)
  {
    //basically check
    if(ISNEIGHBOR(p1i,p1j,p2i,p2j) == 1 &&
       boundaryCheck(p1i, p1j, direc) &&
       boundaryCheck(p2i, p2j, direc)
       )
    {
      switch(direc)
      {
      case 'u':
        if(p1i == p2i)
        {
          mead1 = p1j<p2j ? p1j : p2j;
          mead2 = p1j>p2j ? p1j : p2j;
          if(currGraph[p1i-1][mead1] == 3 && currGraph[p2i-1][mead2] == 2 &&
             RISGOOD(p1i-1) && RISGOOD(p2i-1)) //3 2
          {
            currGraph[p1i][mead1] = 3;
            currGraph[p2i][mead2] = 2;
            currGraph[p1i-1][mead1] = 0;
            currGraph[p2i-1][mead2] = 0;
          }
          else if(currGraph[p1i-1][mead1] == 6 && currGraph[p2i-1][mead2] == 6 &&
                  RISGOOD(p1i-2) && RISGOOD(p2i-2))  // 3 2 6
          {
            currGraph[p1i][mead1] = 6;
            currGraph[p2i][mead2] = 6;
            currGraph[p1i-2][mead1] = 0;
            currGraph[p2i-2][mead2] = 0;
          }
          else  //never meet 0 and when meet 1 4 5 do nothing
          {
            pnode->traList[seed].pick = 'Q';
            return false;
          }
        }
        else
        {
          pnode->traList[seed].pick = 'Q';
          return false;
        }
        break;

      case 'd':
        if(p1i == p2i)
        {
          mead1 = p1j<p2j ? p1j : p2j;
          mead2 = p1j>p2j ? p1j : p2j;
          if(currGraph[p1i+1][mead1] == 3 && currGraph[p2i+1][mead2] == 2 &&
             RISGOOD(p1i+1) && RISGOOD(p2i+1)) //3 2
          {
            currGraph[p1i][mead1] = 3;
            currGraph[p2i][mead2] = 2;
            currGraph[p1i+1][mead1] = 0;
            currGraph[p2i+1][mead2] = 0;
          }
          else if(currGraph[p1i+1][mead1] == 6 && currGraph[p2i+1][mead2] == 6 &&
                  RISGOOD(p1i+2) && RISGOOD(p2i+2))  //3 2 6
          {
            currGraph[p1i][mead1] = 6;
            currGraph[p2i][mead2] = 6;
            currGraph[p1i+2][mead1] = 0;
            currGraph[p2i+2][mead2] = 0;
          }
          else  //0, 1 4 5, 3 2 6
          {
            pnode->traList[seed].pick = 'Q';
            return false;
          }
        }
        else
        {
          pnode->traList[seed].pick = 'Q';
          return false;
        }
        break;

      case 'l':
        if(p1j == p2j)
        {
          mead1 = p1i<p2i ? p1i : p2i;
          mead2 = p1i>p2i ? p1i : p2i;
          if(currGraph[mead1][p1j-1] == 4 && currGraph[mead2][p2j-1] == 5 &&
             CISGOOD(p1j-1) && CISGOOD(p2j-1)) //4 5
          {
            currGraph[mead1][p1j] = 4;
            currGraph[mead2][p2j] = 5;
            currGraph[mead1][p1j-1] = 0;
            currGraph[mead2][p2j-1] = 0;
          }
          else if(currGraph[mead1][p1j-1] == 6 && currGraph[mead2][p2j-1] == 6 &&
                  CISGOOD(p1j-2) && CISGOOD(p2j-2))  //4 5 6
          {
            currGraph[mead1][p1j] = 6;
            currGraph[mead2][p2j] = 6;
            currGraph[mead1][p1j-2] = 0;
            currGraph[mead2][p2j-2] = 0;
          }
          else //0, 1 2 3, 4 5 6
          {
            pnode->traList[seed].pick = 'Q';
            return false;
          }
        }
        else
        {
          pnode->traList[seed].pick = 'Q';
          return false;
        }
        break;

      case 'r':
        if(p1j == p2j)
        {
          mead1 = p1i<p2i ? p1i : p2i;
          mead2 = p1i>p2i ? p1i : p2i;
          if(currGraph[mead1][p1j+1] == 4 && currGraph[mead2][p2j+1] == 5 &&
             CISGOOD(p1j+1) && CISGOOD(p2j+1)) //4 5
          {
            currGraph[mead1][p1j] = 4;
            currGraph[mead2][p2j] = 5;
            currGraph[mead1][p1j+1] = 0;
            currGraph[mead2][p2j+1] = 0;
          }
          else if(currGraph[mead1][p1j+1] == 6 && currGraph[mead2][p2j+1] == 6 &&
                  CISGOOD(p1j+2) && CISGOOD(p2j+2))  //4 5 6
          {
            currGraph[mead1][p1j] = 6;
            currGraph[mead2][p2j] = 6;
            currGraph[mead1][p1j+2] = 0;
            currGraph[mead2][p2j+2] = 0;
          }
          else //0, 1 2 3, 4 5 6
          {
            pnode->traList[seed].pick = 'Q';
            return false;
          }
        }
        else
        {
          pnode->traList[seed].pick = 'Q';
          return false;
        }
        break;
      }

      //after switch
      pnode->traList[seed].pick = 'Q';

      }

    //the two point not be together.
    else
    {
      pnode->traList[seed].pick = 'Q';
      return false;
    }
  }

  else  //meet a 'Q' .pick
  {
    pnode->traList[seed].pick = 'Q';
    return false;
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


bool goForward(Road road, int maxsteps)  //first call function
{
  //the main data is mapCode and the traList.
  Node * pnode;
  pnode = road->rear;  //will change in two way: 1.forward(new graph) 2.retreat

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
    //the traList .pick will all become 'Q'
    pick = pnode->traList[i].pick;  //the way did not go to
    if(pick != 'Q')
      break;
  }

  if(moveRole(road->rear, pnode->traList[i].direc, i))  //current graph had changed.  -cg2  pnode->traList changed too -tl2
  {
    graphToCode(&currCode, currGraph);  //encode
    if(road->total < maxsteps)
      NextStep(currCode, road);
    else
      return false;
  }
  else if(i == 8)  //fail to move and there is no way
    return false;  //will retreat and change the road->rear = road->rear->prenode

  return true;  //continue move
}


bool isFlee(void)
{
  if(currGraph[1][0] == 6 && currGraph[2][0] == 6)
    return true;
  else
    return false;
}



void writeFile(Road road, FILE * pf)
{
  Node * pnode = road->head;
  int hrrgraph[4][5];
  int i, j;
  fprintf(pf, "----------\n");
  while(pnode != NULL)
  {
    codeToGraph(&(pnode->graphc), hrrgraph);
    for(j=4; j>=0; j--)
    {
      for(i=0; i<4; i++)
        fprintf(pf, "%d ",hrrgraph[i][j]);

      fprintf(pf, "\n");
    }
    fprintf(pf, "\n-----------\n");
    pnode = pnode->next;
  }
}


