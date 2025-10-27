#include <bits/stdc++.h>

using namespace std;
int a[1005];
const int mod = 1e3;
void solve(){
    int l, r;
    cin >> a[0] >> a[1] >> l >> r;
    a[0] %= mod;
    a[1] %= mod;
    for(int i = 2; i <= r; i++){
        a[i] = (a[i-1] + a[i-2]) % mod;
    }
    int ans = 0;
    for (int i = l; i <= r; i++){
        ans += a[i];
        ans %= mod;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t --)
        solve();

    return 0;
}