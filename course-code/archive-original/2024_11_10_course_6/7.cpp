#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a = -2;
    char b = 128; // b = -128
    while (a++)
        b += 1;
    printf("%d, %d", a, b);
}