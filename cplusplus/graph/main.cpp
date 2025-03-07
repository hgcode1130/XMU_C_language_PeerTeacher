#include "Circle.h"

void render(Shape* p)
{
	//polymorphism 多态性：向上造型且动态绑定（调用函数由指向对象决定）
	//如果父类函数有重载，想被子类覆盖/重写(override),子类也要有相同重载
	p->render();	//p是多态对象
}

void func()
{
	Ellipse ell(10, 20);
	ell.render();

	Circle circ(40);
	circ.render();

	render(&ell);	//向上造型，但是有virtual，所以还是ellipse类型的
	render(&circ);
}

int main()
{
	Ellipse elly(20, 40);
	Circle circ(60);
	//elly = circ;
	return 0;
}