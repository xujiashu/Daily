#include<stdio.h>
#include<string.h>

//I don't know why it can't run.
void comp(int cube[6][2])
{
  cube[0][1] = cube[1][0] + cube[2][0] + cube[3][0] + cube[4][0];
  cube[1][1] = cube[0][0] + cube[2][0] + cube[3][0] + cube[5][0];
  cube[2][1] = cube[0][0] + cube[1][0] + cube[4][0] + cube[5][0];
  cube[3][1] = cube[2][1];
  cube[4][1] = cube[1][1];
  cube[5][1] = cube[0][1];
  int cp[6][2];
  memcpy(cp, cube, sizeof(cube));
  int i;
  for(i=0; i<6; i++) cube[cp[i][0]-1][1] = cp[i][1];
}
int main()
{
  int cube1[6][2], cube2[6][2];
  int n;
  memset(cube1, 0, sizeof(cube1));
  memset(cube2, 0, sizeof(cube2));
  printf("first cube:\n");
  for(n=0; n<6; n++) scanf("%d", &cube1[n][0]);
  printf("second cube:\n");
  for(n=0; n<6; n++) scanf("%d", &cube2[n][0]);
  comp(cube1);
  comp(cube2);
  int k = 1;
  for(n=0; n<6; n++) if(cube1[n][1] != cube2[n][1]) k = 0;
  if(k) printf("Yes!\n");
  else printf("No!\n");

  return 0;
}
