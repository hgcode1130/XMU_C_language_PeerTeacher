#include <stdio.h>
//6
int f() {
  static int i = 0;
  int s = 1;
  s += i++;
  return s;
}
int main() {
  int i, a = 0;
  for (i = 0; i < 3; i++)
    a += f();
  printf("%d", a);
  return 0;
}