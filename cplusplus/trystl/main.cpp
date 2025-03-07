#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> x;
	for (int a = 0; a < 100; a++)
	{
		x.push_back(a);	//add elements
	}
	vector<int>::iterator p;
	for (p = x.begin(); p < x.end(); p++)
	{
		cout << *p << " ";
	}
	return 0;
}