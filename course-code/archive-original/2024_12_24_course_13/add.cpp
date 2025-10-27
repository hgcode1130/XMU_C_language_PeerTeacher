#include <stdio.h>
#include <string.h>
int N = 100005, la, lb;

void f(int a[], int b[]) {
  // 确定最大的位数
  int i = 0, t = 0, v[N];
  int len = la > lb ? la : lb;

  // 按位进行加法
  for (i = 0; i < len; i++) {
    v[i] = a[i] + b[i];
    v[i] += t;
    t = v[i] / 10;
    v[i] %= 10;
  }
  // 如果最后有进位 数组在加一位存进位
  if (t != 0)
    v[i++] = t;

  // 倒叙运算的数 再倒叙输出
  for (int j = i - 1; j >= 0; j--)
    printf("%d", v[j]);
}

int main() {
  // 定义两个字符串接受输入的数字
  char sa[N], sb[N];
  int a[N], b[N];
  scanf("%s", &sa);
  scanf("%s", &sb);
  // 获取字符串长度
  la = strlen(sa);
  lb = strlen(sb);
  // 翻转输入进去
  for (int i = 0, j = la - 1; i < la; i++, j--)
    a[i] = sa[j] - '0';
  for (int i = 0, j = lb - 1; i < lb; i++, j--)
    b[i] = sb[j] - '0';
  f(a, b);
  return 0;
}