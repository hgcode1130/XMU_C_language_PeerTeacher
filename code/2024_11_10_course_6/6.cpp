#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[11] = {'\0'};
    int sum = 0, i = 0, j = 0;

    for (; i < 10; i++)
        a[i] = 'a' + i;
    //a = "abcdefghij";
    //i = 10
    do {
        a[--i] = a[j++];
        sum += 1;
    } while (i > j);
    // a[9] = a[0] , i = 9 , j  = 1 , sum += 1;
    // a[8] = a[1] , i = 8 , j  = 2 , sum += 1;
    // a[7] = a[2] , i = 7 , j  = 3 , sum += 1; 
    // a[6] = a[3] , i = 6 , j  = 4 , sum += 1;
    // a[5] = a[4] , i = 5 , j  = 5 , sum += 1;
    
    printf("%s\nsum=%d, i=%d, j=%d", a, sum, i, j);
}