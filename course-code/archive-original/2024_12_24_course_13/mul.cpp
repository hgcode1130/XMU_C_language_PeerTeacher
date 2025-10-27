#include <stdio.h>
#include <string.h>
#define N 100010
void cheng(int a[], int b, int m) {
  int t = 0, i, c[N];
  for (i = 0; i < m || t; i++) {
    if (i < m)
      t = a[i] * b + t;
    c[i] = t % 10;
    t = t / 10;
  }
  while (c[i] == 0 && i > 0) i--;
  for (int j = i; j >= 0; j--)
    printf("%d", c[j]);
}

int main() {
  char A[N];
  int a[N], b, m;
  scanf("%s", &A);
  scanf("%d", &b);
  m = strlen(A);
  for (int i = strlen(A) - 1; i >= 0; i--)
    a[m - i - 1] = A[i] - '0';
  cheng(a, b, m);
  return 0;
}