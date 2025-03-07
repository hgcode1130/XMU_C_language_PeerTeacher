#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int a[N];
int main() {
    int n, m;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y; 
        
        int cnt = a[x] / 2; 
        a[x] -= cnt;
        a[y] += cnt;
    }

    int mi = *max_element(a, a + n);
    int mx = *min_element(a, a + n);

    cout << abs(mi - mx) << endl;

    return 0;
}
