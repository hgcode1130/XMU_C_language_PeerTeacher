 #include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    int n;
    cin >> n;
    while(n --){
        cin >> s;
        bool ok = true;
        if (isdigit(s[0])) {
            ok = false;
        }
        for (char c : s) {
            if (!isalnum(c) && c != '_') { 
                ok =  false;
            }
        }
        if(ok){
            cout << "Great" << endl;
        }
        else cout << "Bad" << endl;
    }
    return 0;
}