#include <stdio.h>
#include <string.h>
// 5, world
int main() {
  char b1[12] = "Hello world";
  char b2[12], *pb = b1 + 11;
  while (*(--pb) >= *b1)
    strcpy(b2, pb);
  printf("%d, %s", strlen(b2), b2);
}