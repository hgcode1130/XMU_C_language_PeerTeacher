#include <stdio.h>  /*P 1 */
#include <string.h> /*P 2 */
#define SIZE 50;    /*P 3 */
struct Goods        /*P 4 */
{                   /*P 5 */
  char item[30];    /*P 6 */
  double price;     /*P 7 */
  int count;        /*P 8 */
}; /*P 9 */
int main()                                  /*P 10 */
{                                           /*P 11 */
  struct Goods a[SIZE];                     /*P 12 */
  char strtemp[30];                         /*P 13 */
  int flag;                                 /*P 14 */
  int i;                                    /*P 15 */
  load(a[SIZE]);                            /*P 16 */
  scanf("%s", &strtemp);                    /*P 17 */
  for (i = 0; i < SIZE; i++)                /*P 18 */
  {                                         /*P 19 */
    if (strtemp == a[i].item)               /*P 20 */
    {                                       /*P 21 */
      flag = 1;                             /*P 22 */
      a[i].price += 1.1;                    /*P 23 */
      printf("item is:%s\t", a[i].item);    /*P 24 */
      printf("price is:%lf\t", a[i].price); /*P 25 */
      printf("count is:%d\n", a[i].count);  /*P 26 */
    } /*P 27 */
  } /*P 28 */
  4 if (!flag)                            /*P 29 */
      printf("there is no such item!\n"); /*P 30 */
  return;                                 /*P 31 */
} /*P 32 */
void load(struct Goods a[])                      /*P 33 */
{                                                /*P 34 */
  FILE *fp;                                      /*P 35 */
  int i;                                         /*P 36 */
  if ((fp = fopen("d:\data.dat", "rb")) == NULL) /*P 37 */
  {                                              /*P 38 */
    printf("cannot open file\n");                /*P 39 */
    return;                                      /*P 40 */
  } /*P 41 */
  for (i = 0; i < SIZE; i++)                           /*P 42 */
    if (fread(a[i], sizeof(struct Goods), 1, fp) != 1) /*P 43 */
      printf("file read error\n");                     /*P 44 */
  return;                                              /*P 45 */
} /*P 46 */