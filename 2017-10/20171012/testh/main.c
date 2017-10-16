#include <stdlib.h>
#define NAME "xjs"  //mod.h define NAME would not work
#include "mod.h"

#undef NAME
#define NAME "xjs"  //it would be warned redefined without undef

int testStack(int);
int main()
{
    struct names myName = {
      .firstname="xu",
      .lastname="jiashu"
    };
    printf("%s %s\n", myName.firstname, myName.lastname);
    printf("I'm %s\n", NAME);
    disp();
    ddisp;
    printf("SQUARE:%d\n", SQUARE(5));
    int XNAME(3) = 5;
    XNAME(3) = 3;
    char XNAME(4)[] = "x4";
    printf("XNAME(3):%d\n", x3);
    printf("XNAME(4):%s\n", x4);
    printf("MAX(5,3):%d\n", MAX(5,3));
    printf("ABS(-4):%d\n", ABS(-4));
    testStack(5);

    double sumdb;
    sumdb = sum(5, 1.1, 2.1, 3.1, 4.1, 5.1);
    printf("sum(5, 1.1, 2.1, 3.1, 4.1, 5.1): %g", sumdb);

    return 0;
}

int testStack(int n)
{
  if(n == 0)
    return n;
  else
    return testStack(n-1);
}
