#include<string.h>
#include<stdbool.h>
#include<stdio.h>

#define A00 0x00000003
#define A01 0x0000000C
#define A02 0x00000030
#define A03 0x000000C0
#define A10 0x00000300
#define A11 0x00000C00
#define A12 0x00003000
#define A13 0x0000C000
#define A20 0x00030000
#define A21 0x000C0000
#define A22 0x00300000
#define A23 0x00C00000

#define B30 0x00000003
#define B31 0x0000000C
#define B32 0x00000030
#define B33 0x000000C0
#define B40 0x00000300
#define B41 0x00000C00
#define B42 0x00003000
#define B43 0x0000C000

//#define PointA(Ia,Ja) A ## Ia ## Ja
//#define PointB(Ib,Jb) B ## Ib ## Jb

#define Empty 0x00000000  //0
#define Bing  0x55555555  //1
#define HZ    0xAAAAAAAA  //2
#define Boss  0xFFFFFFFF  //3

struct position{
  int i;
  int j;
};

typedef struct map_code{
  int codea;
  int codeb;
}mapCode;

