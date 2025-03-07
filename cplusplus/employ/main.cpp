#include "Manager.h"

int main()
{
	Employee bob("Bob Jones", "55544000");
	Manager bill("Bill Smith", "666551234", "Important Person");

	string name = bill.get_name();
	cout << bill.title_name() << endl;
	bill.print(cout);
	bob.print(cout);
	bob.print(cout, "Employee:");
	return 0;
}
/*
调用内联函数时，不通过函数调用的机制而是通过将函数体直接插入调用处来实现的，头文件和cpp文件都要重复inline

编译器同时只能看到一个文件，所以在看main.cpp时，只能看到有内联，却无法插入内联函数内容
解决方案：将内联函数body放到头文件中

通常编写函数时，会把声明放到头文件（*.h）中，而把函数定义放在源文件（*.cpp）中，在其他源文件中使用时包含对应的头文件即可。
但是内联函数（inline）不要定义在cpp文件中，因为我们通常都是包含头文件，而编译器在编译时会对内联函数进行展开操作，
但是编译器只能在包含的头文件里搜索函数的定义体，如果头文件只有声明，显然编译器不知道该如何展开，于是就出错了。
每一个使用内联函数的地方，都应该知道内联函数的定义，所以内联函数就直接定义在头文件中。
*/

/*引用
char &r=c;		//r是c的引用，可等效替换
	定义时必须初始化，除非是成员变量(但构造函数的初始化列表必须将其初始化)
	作为函数形参时，must have a location(variable)
		比传递对象更有效率，且比传递指针更简洁
		const修饰引用时，在函数内部不能修改（做左值）
	返回引用时，返回结果可做左值	int& h(){}	返回值不能是本地变量
		如果用const修饰函数时，返回结果不可做左值
const int& z=x;	//不能通过z修改x
引用的地址不可访问，所以
int&* p;	//illegal
int*& p;	//ok
离p最近的决定了基本类型
*/