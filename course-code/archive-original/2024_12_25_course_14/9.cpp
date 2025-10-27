#include <stdio.h>
#include <string.h>
// 1, abc, ef, g
int main() {
  struct st {
    int a;
    char b[4];
  } arr[3] = {1, "abc", 2, "def", 3, "ghi"};
  struct st *p = arr;
  printf("%d, %s, ", p->a, p->b);
  printf("%s, %c", ((p + 1)->b) + 1, *((p + 2)->b));
}