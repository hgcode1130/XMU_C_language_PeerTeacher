#include "Integer.h"
const Integer operator+(const Integer& lhs, const Integer& rhs)
{
	//友元函数，所以定义不能放在h文件中
	//glogbal operators(friend)
	return Integer(lhs.i + rhs.i);
}

/*
Integer::operator double() const
{
	return (double)this->i;
}
*/