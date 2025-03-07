#pragma once
#include <iostream>
using namespace std;
class VectorIndexError
{
public:
	VectorIndexError(int v):m_badValue(v){}
	~VectorIndexError() {}
	void diagnostic()
	{
		cerr << "index " << m_badValue << " out of range!" << endl;
	}
private:
	int m_badValue;
};

