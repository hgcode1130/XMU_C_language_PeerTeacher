#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x = 3, y = 4, z = 5, a = 7, m = 011, n = 0x5a; // m = 9, n = 90
    float b = 2.5, c = 4.7, t;
    char c1 = '\101', c2 = '\x42';

    t = b + a % 3 * (int)(b + c) % 2 / 4;
    if (!(x < y))
        printf("%c%c\n", c1, c2);
    if (y + z)
        printf("%f\n", t);
    else
        printf("%d%d\n", m, n);
    printf("%d\n", n %= (m / 2));

    return 0;

}