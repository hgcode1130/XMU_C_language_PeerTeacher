#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long i64;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
int a[10];
int id[10];
void solve() {
   int n , m;
   scanf("%d, %d", &n, &m);
   int cnt = 0;//记录有效票数
   for(int i = 1 ; i <= m ; i ++) id[i] = i;
   for (int i = 0; i < n; i++) {
      int vote;
      scanf("%d", &vote);
        
      if((vote > 0) && (vote <= m)) cnt++ , a[vote] += 1;//有效票数+1
   }
   if(cnt < n * 2.0 / 3) printf("无效投票!\n");
   else
   {
        //冒泡排序一下就好了
        for(int i = 1 ; i <= m - 1 ; i ++)
            for(int j = i + 1 ; j <= m - i ;  j ++)
                if(a[i] < a[j])
                {
                    swap(id[i], id[j]);
                    swap(a[i], a[j]);
                }
        for(int i = 1 ; i <= m ; i ++)
        {
            if(a[i] > 0)
            {
                printf("NO %d : %d 票\n", id[i] , a[i]);
            }
        }
   }

}

signed main() {
    int t = 1;
    while (t --) solve();
    return 0;
}