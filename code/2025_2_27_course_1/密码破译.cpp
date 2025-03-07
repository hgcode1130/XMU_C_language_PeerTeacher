#include <bits/stdc++.h>

using namespace std;
int c[100];
int main(){
    string a;
    cin >> a;
    for(int i = 0; i < a.size(); i++){
        c[a[i]] = i + 'A';
    }
    string b;
    while(cin >> b){
        for(int i = 0; i < b.size(); i++){
            b[i] = c[b[i]];
        }
        cout << b << " ";
    }
}