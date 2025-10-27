#include<bits/stdc++.h>

using namespace std;
struct Node{
    char c;
    int count;
}node[1001];
int cnt = 0;
int mp[150];
bool cmp(Node a, Node b)  {
    if(a.count!= b.count) return a.count > b.count;
    return a.c > b.c;
}
int main(){
    string str;
    while(cin >> str){
        for(int i = 0; i < 150; i++) mp[i] = 0;
        for(int i = 0; i < str.length(); i++){
            mp[str[i]]++;
        }
        for (int i = 0; i < 150; i++){
            if(mp[i] > 0){
                node[cnt].c = i;
                node[cnt].count = mp[i];
                cnt++;
            }
        }
        sort(node, node + cnt,cmp);
        for(int i = 0; i < cnt; i++){
            cout << node[i].c << ":" << node[i].count << " ";
        }
        cout << endl;
        cnt = 0;
    }

}