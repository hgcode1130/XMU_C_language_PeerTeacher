#include <stdio.h>
const int N = 15;
// 当前来到了第几位，从哪个数开始枚举
int vis[N]; // 表示数字i有没有被选择过
int path[N];
int n, m;
// 我正在选第u个数且从start开始枚举
void dfs(int u, int start) {
  if (u == m + 1) {
    for (int i = 1; i <= m; i++)
      printf("%d ", path[i]);
    printf("\n");
    return;
  }
  for (int i = start; i <= n; i++) {
    if (!vis[i]) {
      vis[i] = 1;
      path[u] = i;
      dfs(u + 1, i + 1);
      vis[i] = 0;
      path[i] = 0;
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  dfs(1, 1);
  return 0;
}