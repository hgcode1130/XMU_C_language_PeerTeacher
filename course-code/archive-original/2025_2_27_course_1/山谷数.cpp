#include <bits/stdc++.h>

using namespace std;

int main(){

    string x;
    
    while(cin >> x){
        bool ok = true;
        for(int i = 1; i < x.size() - 1; i++){
            bool f1 = false, f2 = false;
            for (int j = i - 1; j >= 0; j--){
                if(x[j] < x[i]) f1 = true;
                else if(x[j] == x[i]) continue;
                else break;
            }
            for (int j = i + 1; j < x.size(); j++){
                if(x[j] < x[i]) f2 = true;
                else if(x[j] == x[i]) continue;
                else break;
            }
            if(f1 && f2) {
                ok = false;
            }
        }
        if(!ok) cout << "No" << endl;
        else
        cout << "Yes" << endl;
    }

    return 0;
}