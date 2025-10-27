#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[10001];
int main() {
    int n;
    while(cin >> n){

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a, a + n, greater<int>()); // 降序排序
        
        int ans = -1;
        for (int i = 0; i < n - 2; ++i) {
            if (a[i] < a[i+1] + a[i+2]) {
                ans = a[i] + a[i+1] + a[i+2];
                break; // 找到最大周长即可结束
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
