#include<bits/stdc++.h>
using namespace std;
int main()
{
    int w = 3, z = 7, x = 10, y = 20;
    printf("%d,", x > y > z);
    printf("%d,", x > 10 ? x + 100 : x - 10);
    printf("%d,", !(w = z) | 0 && (w = x));
    printf("%d\n", y -= x *= w);
    return 0;

}