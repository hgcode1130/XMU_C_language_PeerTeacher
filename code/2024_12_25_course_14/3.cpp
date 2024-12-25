#include <stdio.h>
//45
int main() {
  int i, k = 5, p[3];
  int a[10] = {2, 2, 9, 2, 0, 1, 9, 2, 2, 0};
  for (i = 0; i < 3; i++)
    p[i] = a[i * (i + 1)];
  for (i = 0; i < 3; i++)
    k += p[i] * 2;
  printf("%d", k);
}