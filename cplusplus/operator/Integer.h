#pragma once
#include <iostream>
/*
单目应该为成员
= () [] -> ->* 必须为成员
所有其他二元运算符为非成员
*/
class Integer
{
public:
	Integer(int n = 0) :i(n) {}
	/*
	const Integer operator+(const Integer& n) const
	{
		return Integer(i + n.i);//返回值为const，否则可为左值
	}
	*/
	const Integer operator-() const
	{
		return Integer(-i);
	}
	friend const Integer operator+(const Integer& lhs, const Integer& rhs);
		//glogbal operators(friend)
	//operator double() const;
	void print() { std::cout << i << std::endl; }
private:
	int i;
};

