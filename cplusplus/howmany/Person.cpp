#include "Person.h"
#include <cstring>
using namespace std;

Person::Person(const char* s)
{
	name = new char[::strlen(s) + 1];
	::strcpy_s(name, 20, s);
}
//private针对类而非对象，所以可以访问同类对象的private成员
Person::Person(const Person& w)
//如果拷贝string，可以用自动生成的拷贝构造
{
	name = new char[::strlen(w.name) + 1];
	::strcpy_s(name, 20, w.name);
}

Person::~Person()
{
	delete [] name;
}