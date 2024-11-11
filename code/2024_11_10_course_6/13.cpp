#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long i64;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int a[50];
void solve() {
   int n , l , r;
   scanf("%d", &n);
   //差分的做法
//    for (int i = 0; i < n; i++) {
//       scanf("%d%d", &l ,&r);
//       a[l] += 1;
//       a[r + 1] -= 1;
//    }
//    int ans = 0;
//    for(int i = 1 ; i <= 24 ; i ++) a[i] += a[i - 1] , ans = max(ans, a[i]);
    //暴力做法
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l ,&r);
       for (int j = l; j <= r; j++) a[j] += 1;
    }
    int ans = 0;
    for(int i = 1 ; i <= 24 ; i ++) ans = max(ans, a[i]);
    printf("%d\n", ans);
}

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t --) solve();
    return 0;
}