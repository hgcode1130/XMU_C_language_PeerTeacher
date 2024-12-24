#include <stdio.h>
#include <string.h>
#define N 100010
int cmp(char a[], char b[]) {
  if (strlen(a) != strlen(b)) {
    if (strlen(a) > strlen(b))
      return 1;
    else
      return 0;
  }
  for (int i = 0; i < strlen(a); i++)
    if (a[i] != b[i]) {
      if (a[i] > b[i])
        return 1;
      else
        return 0;
    }

  return 1;
}
void sub(int a[], int b[], int m, int n) {
  int c[N], t = 0;
  for (int i = 0; i < m; i++) {
    t = a[i] - t;
    if (i < n)
      t = t - b[i];
    c[i] = (t + 10) % 10;
    if (t < 0)
      t = 1;
    else
      t = 0;
  }
  //去除前导0
  while (c[m - 1] == 0 && m - 1 > 0) m--;
  for (int i = m - 1; i >= 0; i--)
    printf("%d", c[i]);
}
int main() {
  char A[N], B[N];
  int a[N], b[N], m, n;
  scanf("%s%s", &A, &B);
  m = strlen(A);
  n = strlen(B);
  for (int i = strlen(A) - 1; i >= 0; i--)
    a[m - i - 1] = A[i] - '0';
  for (int i = strlen(B) - 1; i >= 0; i--)
    b[n - i - 1] = B[i] - '0';
  if (cmp(A, B) == 1)
    sub(a, b, m, n);
  else {
    printf("-");
    sub(b, a, n, m);
  }
  return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// char t1[100002], t2[100002];
// int a[100002], b[100002], c[100002], al, bl, cl;
// int len1, len2;
// char op;
// int cmp() {
//   if (len1 < len2)
//     return -1;
//   else if (len1 > len2)
//     return 1;
//   for (int i = 0; i < len1; i++) {
//     if (t1[i] < t2[i])
//       return -1;
//     if (t1[i] > t2[i])
//       return 1;
//   }
//   return 0;
// }
// void work(char t1[], char t2[]) {
//   al = len1, bl = len2, cl = max(al, bl);
//   for (int i = 1; i <= al; i++)
//     a[i] = t1[al - i] - '0';
//   for (int i = 1; i <= bl; i++)
//     b[i] = t2[bl - i] - '0';

//   for (int i = 1; i <= cl; i++) {
//     if (a[i] - b[i] < 0)
//       a[i] += 10, a[i + 1]--;
//     c[i] = a[i] - b[i];
//   }
//   while (cl && !c[cl])
//     cl--;
//   if (!cl)
//     printf("%d", 0);
//   else {
//     printf("%c", op);
//     for (int i = cl; i > 0; i--)
//       printf("%d", c[i]);
//   }
// }
// int main() {
//   scanf("%s%s", t1, t2);
//   len1 = strlen(t1), len2 = strlen(t2);
//   if (cmp() < 0)
//     op = '-', work(t2, t1);
//   else
//     work(t1, t2);
// }