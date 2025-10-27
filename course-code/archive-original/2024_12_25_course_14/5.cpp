#include <stdio.h>
char f(char x, char y) {
  if (x < y)
    return x;
  return y;
}
//7
int main() {
  char a = '9', b = '8', c = '7';
  printf("%c", f(f(a, b), f(b, c)));
  return 0;
}