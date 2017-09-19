#include<stdio.h>
#include<string.h>
#define FA (6)
#define FB (2)
//fix the bug.
int cube1[FA][FB], cube2[FA][FB], cp[FA][FB];

void comp(int cube[FA][FB])
{
  cube[0][1] = cube[1][0] + cube[2][0] + cube[3][0] + cube[4][0];
  cube[1][1] = cube[0][0] + cube[2][0] + cube[3][0] + cube[5][0];
  cube[2][1] = cube[0][0] + cube[1][0] + cube[4][0] + cube[5][0];
  cube[3][1] = cube[2][1];
  cube[4][1] = cube[1][1];
  cube[5][1] = cube[0][1];
  memcpy(cp, cube, sizeof(cube));
  int i;
  for(i=0; i<FA; i++)
  {
    int j;
    j = cp[i][0] - 1;  //cp[i][0]-1 is 0-5 
    cube[j][1] = cp[i][1];
  }

}
int main()
{
  int n;
  memset(cube1, 0, sizeof(cube1));
  memset(cube2, 0, sizeof(cube2));
  printf("first cube:\n");  //the input is forced to 1-6
  for(n=0; n<FA; n++) scanf("%d", &cube1[n][0]);
  printf("second cube:\n");
  for(n=0; n<FA; n++) scanf("%d", &cube2[n][0]);
  comp(cube1);
  comp(cube2);
  int k = 1;  //judge flag
  for(n=0; n<FA; n++) if(cube1[n][1] != cube2[n][1]) k = 0;
  if(k) printf("Yes!\n");
  else printf("No!\n");

  return 0;
}
//have a bug that it will mistaken the cube
//ex: 1 2 3 4 5 6 and 6 2 3 4 5 1

