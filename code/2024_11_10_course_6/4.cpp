#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i = 0, k = 0,p[7] = {11, 13, 14, 15, 16, 17, 18};
    while (p[i] % 2 && i < 7)
        k = k + p[++i];
    //第一步 k = 13
    //k = 27
    printf("%d, %d\n", k, i);
}