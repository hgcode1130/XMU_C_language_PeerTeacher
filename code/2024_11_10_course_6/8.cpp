#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10] = {3, 4, 6, 1, 3, 7, 6, 2, 5, 4};
    int i, j, k = 0, e = 0;
    for (i = 0; i <= 9; i++)
        for (j = 0; j <= 9; j++) {
            if ((a[i] == a[j]) && (i != j)) {
                k++;
                break;
            }

            if (j == 9) {
                if (e == 0)
                    printf("%d", a[i]);
                else
                    printf(" %d", a[i]);
                e++;
            }
        }
    return 0;   
}