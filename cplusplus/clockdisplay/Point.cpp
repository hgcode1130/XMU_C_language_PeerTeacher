#include "Point.h"
/*
Point::Point(int a, int b)
{
	x = a;
	y = b;
	cout << "constructor" << endl<<x <<endl<< y<<endl;
}
*/

// 类::		对象.		指针->
Point::Point(int a,int b):x(a),y(b)
//initialization在construct之前
{
	cout << "constructor" << endl << x << endl << y << endl;
}

Point::~Point()
{
	cout << "destructor" << endl;
}

B::B() :Point(3, 4)
{ 
	cout << "构造子类" << endl; 
	//先构造父类后构造子类
};

B::~B()
{
	cout << "析构子类" << endl;
	//先析构子类后析构父类
};