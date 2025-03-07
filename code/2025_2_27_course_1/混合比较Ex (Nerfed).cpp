#include <bits/stdc++.h>

using namespace std;
int a[1005];
const int mod = 1e3;
int b[100];
int cnt = 0;
void work(string temp){
    int x = 0;
    if(temp[0] == '0'){
        if(temp[1] == 'x'){
            for(int j = 2; j < temp.size(); j ++){
                if(temp[j] <= '9' && temp[j] >= '0') {
                    x = x * 16 + (temp[j] - '0');
                }
                else x = x * 16 + (temp[j] - 'a' + 10);
            } 
        }
        else if(temp[1] == 'b'){
            for(int j = 2; j < temp.size(); j ++){
                x = x * 2 + (temp[j] - '0');
            }
        }
        else{
            for(int j = 1; j < temp.size(); j ++){
                x = x * 8 + (temp[j] - '0');
            }
        }
    }
    else{
        for(int j = 0; j < temp.size(); j ++){
            x = x * 10 + (temp[j] - '0');
        }
    }
    b[cnt ++] = x;    
}
void solve(){
    string a;
    cin >> a;
    string temp;  
    for (int i = 0; i < a.size(); i ++){
        if(a[i] != ','){
            temp += a[i];
        }
        else{
            work(temp);
            temp.clear();
        }
    }
    work(temp);
    sort(b, b + cnt);
    for (int i = 0; i < cnt; i ++)
        cout << b[i] << ",\n"[i == cnt - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}