#include<bits/stdc++.h>
using namespace std;
int main()
{
    //输入为20241108Xmu
    int a = 0, b = 0, s = 0, t = 0;
    char c;
    for (; (c = getchar()) != '\n';)
    switch (c) {
        case '0': 
        case '1': a++; break;
        case '2': 
        case '3': b++; break;
        default:
            c >= 'A' && c <= 'Z' ? s++ : t++;
    }
    //b = 1
    //a = 1 , b = 1
    //a = 1 , b = 2
    //a = 1 , b = 2 , t = 1
    //a = 3 , b = 2 , t = 1
    //a = 4 , b = 2 , t = 1
    //a = 4 , b = 2 , t = 2
    //a = 4 , b = 2 , s = 1 , t = 2
    //a = 4 , b = 2 , s = 1 , t = 4
    printf("%d %d %d %d", a, b, s, t);

}