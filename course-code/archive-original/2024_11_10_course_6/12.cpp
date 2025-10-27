#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long i64;
typedef pair<int, int> PII;

void solve() {
   int x0 , y0 , p0 , r0 , N;
   scanf("%d%d%d%d%d", &x0, &y0, &p0, &r0, &N);
   int x , y , m , p , r;
   int res = 0;
   for (int i = 0; i < N; i++) {
      scanf("%d%d%d%d%d", &x, &y, &m, &p ,&r);
      int dist = (x - x0) * (x - x0) + (y - y0) * (y - y0);
      if(dist <= r0 * r0 && m <= p0) 
        {
            res ++;
            printf("可以\n");
        }
      else printf("不可以\n");
   }
    printf("%d\n", res);
}

signed main() {
    int t = 1;
    while (t --) solve();
    return 0;
}