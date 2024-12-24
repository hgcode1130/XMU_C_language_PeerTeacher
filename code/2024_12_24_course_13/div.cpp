#include <stdio.h>
#include <string.h>
#define N 100010
void chu(int a[], int b, int m) {
  int t = 0, c[N];
  for (int i = m - 1; i >= 0; i--) // 00020
  {
    t = a[i] + t * 10;
    c[i] = t / b;
    t = t % b;
  }
  while (c[m - 1] == 0 && m - 1 > 0)
    m--;
  for (int i = m - 1; i >= 0; i--)
    printf("%d", c[i]);
  printf("\n");
  printf("%d", t);
}
int main() {
  char A[N];
  int b, a[N], m;
  scanf("%s", &A); // 123456
  scanf("%d", &b);
  m = strlen(A);
  for (int i = m - 1; i >= 0; i--)
    a[m - i - 1] = A[i] - '0'; // 654321
  chu(a, b, m);
  return 0;
}