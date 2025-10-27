#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x[3][3] = {{1}, {1, 2}, {2}}, i;
    //2 0 2
    //1 4 0
    //2 0 0
    for (i = 0; i < 3; i++) {
        x[i][i] *= 2;
        if (x[i][2 - i] != 0) break;
        x[i][2 - i] = x[2 - i][i];
    }

    printf("%d, %d, %d, %d\n",x[0][0], x[1][1], x[2][0], x[2][2]);
    return 0;

}