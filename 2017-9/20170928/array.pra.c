#include<stdio.h>
#define ROWS 3
#define COLS 4

void sum_rows(int [][COLS], int);
void sum_cols(int (*ar)[COLS], int rows);
int sum2d(int ar[][COLS], int rows);
int varSum2d(int, int, int ar[*][*]);
int sum(int *ar, int);

int main()
{
  int junk[ROWS][COLS] = {
  {2,4,6,8},
  {3,5,7,9},
  {12,10,8,6}
  };
  int moreJunk[ROWS-1][COLS+2] = {
  {20,30,40,50,60,70},
  {5,6,7,8,9,10}
  };
  
  sum_rows(junk, ROWS);
  sum_cols(junk, ROWS);
  printf("Sum of all elements = %d\n", sum2d(junk, ROWS));
  printf("3x4 array\n");
  printf("Sum of all elements = %d\n", varSum2d(ROWS, COLS, junk));
  printf("2x6 array\n");
  printf("Sum of all elements = %d\n", varSum2d(ROWS-1, COLS+2, moreJunk));


  int total[3];
  int *pt1;
  int (*pt2)[COLS];
  int i;

  pt1 = (int [2]){10,20};
  pt2 = (int [2][COLS]){{1,2,3,-9},{4,5,6,-8}};
  total[0] = sum(pt1, 2);
  total[1] = sum2d(pt2, 2);
  total[2] = sum((int []){4,4,4,5,5,5}, 6);
  for(i=0; i<3; i++)
    printf("total%d = %d\n", i, total[i]);

  return 0;
}

void sum_rows(int ar[][COLS], int rows)
{
  int r;
  int c;
  int tot;
  for(r=0; r<rows; r++)
  {
    tot = 0;
    for(c=0; c<COLS; c++) tot += ar[r][c];

    printf("row %d: sum = %d\n", r, tot);
  }
}

void sum_cols(int ar[][COLS], int rows)
{
  int r;
  int c;
  int tot;
  for(c=0; c<COLS; c++)
  {
    tot=0;
    for(r=0; r<rows; r++) tot += ar[r][c];

    printf("col %d: sum = %d\n", c, tot);
  }
}

int sum2d(int ar[][COLS], int rows)
{
  int r;
  int c;
  int tot;
  tot = 0;
  for(r=0; r<rows; r++)
    for(c=0; c<COLS; c++)
      tot += ar[r][c];
  return tot;
}

int varSum2d(int rows, int cols, int ar[rows][cols])
{
  int r;
  int c;
  int tot;
  tot = 0;
  for(r=0; r<rows; r++)
    for(c=0; c<cols; c++)
      tot += ar[r][c];
  return tot;
}

int sum(int ar[], int n)
{
  int i;
  int total = 0;
  for(i=0; i<n; i++)
    total += ar[i];
  return total;
}
