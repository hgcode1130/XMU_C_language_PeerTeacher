#include <stdio.h>
// 1, 0, 6, 0
int main() {

  char c = 'k';
  int i = 1, j = 2, k = 3;
  float x = 3e+5, y = 0.85;
  int a1 = x || i && j - 3, a2 = !!!x;
  int a3 = i + j + k;
  int a4 = (j = 8) && c && i == 5;
  printf("%d, %d, %d, %d", a1, a2, a3, a4);
  
}