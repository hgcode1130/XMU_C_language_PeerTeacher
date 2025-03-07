#pragma once
#include <iostream>
using namespace std;
//class缺省private		struct缺省public
class Point
{
public:
	void init(int x, int y);
	void print() const;
	void move(int dx, int dy);
	Point(int a, int b);
	~Point();
private:
	int x;
	int y;
};

class B :public Point
{
public:
	//父类初始化必须放在初始化列表中
	B();	//顺序是声明时的顺序;交给父类初始化
	~B();
};