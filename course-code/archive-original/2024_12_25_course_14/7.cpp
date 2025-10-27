#include <stdio.h>
#include <string.h>
// 8
// 0, 3, 0, 6, 0, 3, 0,
int f(int a) {
  if (a > 6)
    return a;
  return f(a += 2);
}
void g(int a) {
  if (a >= 3)
    g(a - 3);
  printf("%d, ", a);
  if (a >= 3)
    g(a - 3);
}
int main() {
  printf("%d\n", f(2));
  g(6);
  return 0;
}