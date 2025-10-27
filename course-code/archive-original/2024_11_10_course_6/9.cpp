#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[10] = "2024_exam";
    int i, j, k;
    for (i = 0; str[i] != '\0'; i += 2) {
        char tempstr = str[i];
        str[i] = str[i + 1];
        str[i + 1] = tempstr;
    }
    printf("%d\n%s", strlen(str), str);
    return 0;
}