#include "Integer.h"

int main()
{
	Integer x(1), y(5);
	/*
	Integer z = x + 3;
	//x为receiver，自动构造i为3的Integer(自动类型转换，但如果用explicit修饰构造函数则无法自动类型转换)
	Integer out = x.operator+(y);//x为receiver
	//Integer w = 3+ y;	//x
	Integer w = -x;
	w.print();
	z.print();
	out.print();
	*/
	Integer z = 3 + y;
	z.print();
}