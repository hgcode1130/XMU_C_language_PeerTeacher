#include <stdio.h>
#include <string.h>
// 1, 1, 1, 1A34
int main() {
  union un {
    char a[5];
    char b, c, d, e;
  } f = {"1234"};
  printf("%c, %c, ", f.a[0], f.c);
  char *q = &f.c;
  *(q + 1) = 'A';
  printf("%c, %s ", *q, f.a);
}