#include<string.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

#define P14 07
#define P13 070
#define P12 0700
#define P11 07000
#define P10 070000
#define P04 0700000
#define P03 07000000
#define P02 070000000
#define P01 0700000000
#define P00 07000000000

//#define PointA(Ia,Ja) A ## Ia ## Ja
//#define PointB(Ib,Jb) B ## Ib ## Jb

#define Empty 0x0  //0
#define Bing  01111111111  //1
#define ZFH   02222222222  //2 head vertical
#define ZFT   03333333333  //3 tail
#define GYH   04444444444  //4 head horizontal
#define GYT   05555555555  //5 tail
#define Boss  06666666666  //6

#define RISGOOD(x) ((x)>=0 && (x) <= 4)  //i
#define CISGOOD(x) ((x)>=0 && (x) <=5)  //j
#define ISNEIGHBOR(x,y) ((x)-(y)>0 ? (x)-(y) : (y)-(x))


typedef struct position{
  unsigned short i;
  unsigned short j;
}Posit;  //to record the empty position

typedef struct map_code{
  int codea;
  int codeb;
  Posit posA;  //indicate the position
  Posit posB;  //indicate the position
}mapCode;

typedef struct tract{
  Posit posA;
  Posit posB;
  char pick;
  char direc;
}Tract;

typedef struct node{  //equal to each step
  mapCode graphc;
  Tract traList[8];   //record the road had been go to
  struct node * next;
  struct node * prenode;
}Node;

struct hrroad{
  Node * head;
  Node * rear;
};

typedef struct hrroad * Road;

//func.c
void codeToGraph(const mapCode * code, int (*HRR)[5]);
void graphToCode(mapCode * code, int (*HRR)[5]);
bool moveRole(Road road, char direc, int seed);
bool goForward(Road road);
bool isFlee(void);
void disp(Road road);

//listFunc.c
void InitList(Road road);
bool IsEmpty(const Road road);
bool IsFull(const Road road);
unsigned int StepCount(const Road road);
bool NextStep(mapCode code, Road road);
void Traverse(const Road road, void (* pfun)(mapCode code));
void EmptyList(Road road);
void Retreat(Road road);


