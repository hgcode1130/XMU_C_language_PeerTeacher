#include<bits/stdc++.h>

using namespace std;

struct Node{
    int num;
    int t;
    string ans;
}node[1001];

bool cmp(Node a, Node b)  {
    if(a.num != b.num) return a.num > b.num;
        return a.t < b.t;
}

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    string s;
    for (int i = 0; i < x + y + z; i++){
        node[i].t = i;
        int num = 0;
        if(i < x){
            cin >> node[i].num;
            node[i].ans = to_string(node[i].num);
        }
        else if(i < x + y){
            cin >> s;
            for(int j = 0; j < s.length(); j++){
                num = num * 8 + (s[j] - '0');
            }
            node[i].num = num;
            node[i].ans = s;
        }
        else{
            cin >> s;
            for(int j = 0; j < s.length(); j++){
                if(s[j] >= '0' && s[j] <= '9')
                    num = num * 16 + (s[j] - '0');
                else num = num * 16 + (s[j] - 'a' + 10);
            }
            node[i].num = num;
            node[i].ans = s;
        }
    }
    sort(node, node + x + y + z, cmp);
    cout << node[0].ans << endl;
    return 0;
}