#include <stdio.h>
#include <stdlib.h>
#include"HRRoad.h"


int PointA[2][5] = {
  {P00, P01, P02, P03, P04},
  {P10, P11, P12, P13, P14}
};

int PointB[2][5] = {
  {P00, P01, P02, P03, P04},
  {P10, P11, P12, P13, P14}
};

static void writeFile(Road road, FILE * pf);



int main()
{
  char fileName[200];
  struct hrroad firstGraph;
  int startGraph[4][5];
  Road fleeWay;
  int i, j;
  int maxsteps;
  mapCode firstCode;
  FILE * pf;



  fleeWay = &firstGraph;
  InitList(fleeWay);

  puts("name: ");
  gets(fileName);
  pf = fopen(fileName, "w+");

  puts("First Graph: ");
  for(i=0; i<4; i++)
    for(j=0; j<5; j++)
      scanf("%d", &startGraph[i][j]);
  while(getchar() != '\n')
    continue;
  graphToCode(&firstCode, startGraph);
  NextStep(firstCode, fleeWay);

  puts("Max steps: ");
  scanf("%d", &maxsteps);

  //----------------------


  while(true)
  {
    if(goForward(fleeWay, maxsteps))
    {
      if(isFlee())
        break;
      else
        continue;
    }
    else
    {
      Retreat(fleeWay);
    }
  }

  puts("Find the way.");
  writeFile(fleeWay, pf);


  EmptyList(fleeWay);

  return 0;
}


static void writeFile(Road road, FILE * pf)
{
  Node * pnode;
  pnode = road->head;
  int graph[4][5];
  int i, j;

  while(pnode != NULL)
  {
    codeToGraph(&(pnode->graphc), graph);
    for(j=4; j>=0; j--)
    {
      for(i=0; i<4; i++)
        fprintf(pf, "%d ", graph[i][j]);
      fprintf(pf, "\n");
    }
    fprintf(pf, "\n----------\n");
    pnode = pnode->next;
  }
}


