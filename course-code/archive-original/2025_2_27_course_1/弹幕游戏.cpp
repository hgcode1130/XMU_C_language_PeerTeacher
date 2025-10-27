 #include <bits/stdc++.h>
using namespace std;

double a[101][3];
int main() {
    int n, p;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    cin >> p;
  
    bool ok = true;
    for (int i = 1; i <= n; i++){
        if(i != p + 1){
            if((a[i][0] - a[p + 1][0]) * (a[i][0] - a[p + 1][0]) + (a[i][1] - a[p + 1][1]) * (a[i][1] - a[p + 1][1]) >= (a[i][2] + a[p + 1][2]) * (a[i][2] + a[p + 1][2])){
                continue;
            }
          	else ok = false;
        }
    }
    
  	if(ok)
        cout << "Alive" << endl;
    else cout << "Biu" << endl;
    return 0;
}