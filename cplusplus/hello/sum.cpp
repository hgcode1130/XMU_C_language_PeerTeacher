#include <iostream>
using namespace std;

int sum(void)
{
    int num, sum = 0;
    while (cin >> num)
    {
        sum = sum + num;
    }
    cout << sum << endl;
    return sum;
}