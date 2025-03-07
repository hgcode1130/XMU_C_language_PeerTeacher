#pragma once
#include "XYPos.h"
class Shape
{
public:
	Shape();
	virtual ~Shape();	//只要有virtual的成员函数，则析构也必须为Virtual
	virtual void render();
	//如果Shape的子类有同名函数，则两函数有联系
	void move(const XYPos&);
	virtual void resize();
protected:
	XYPos center;
};

