#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, t, sum = 0;
    for (t = i = 1; i <= 6; i++) {
        sum += t;
        if (i % 3 == 0) continue;
        else t = i;
    }
    //sum += 1
    //sum += 1
    //sum += 2
    //sum += 2
    //sum += 4
    //sum += 5
    printf("sum=%d, i=%d", sum, i);

    return 0;
}