#include <iostream>
#include <string>
using namespace std;
/*
新建一个类
	constructor
	virtual destructor
	copy constructor
*/
static int objectCount = 0;

class HowMany
{
public:
	HowMany() { objectCount++; print("HowMany()"); }
	HowMany(int i){ objectCount++; print("HowMany(int)"); }
	HowMany(const HowMany& o) { objectCount++; print("HowMany(HM)"); }
	/*拷贝构造	T::T(const T&)
		默认会给拷贝构造，但是没有自定义的print,同时复制每一个成员变量（包括成员对象，也包括指针，string也一样）
			如果拷贝指针，则两指针指向同一块地址，析构的时候析构两次，所以会出错
			如果拷贝string，可以用自动生成的拷贝构造
		使用拷贝构造
			隐藏场景：调用函数时，函数参数为对象本身（而非引用或指针）
						函数返回对象时，
			直接场景：初始化，例如h3,h4
	*/
	void print(const string& msg = "")
	{
		if (msg.size() != 0)
		{
			cout << msg << ": ";
		}
		cout << "objectCount = " << objectCount << endl;
	}
	~HowMany()
	{
		objectCount--;
		print("~HowMany()");
	}

};

HowMany f(HowMany x)
{
	//构造过程没有通过构造函数实现
	cout << "begin of f" << endl;
	x.print("x argument inside f()");
	cout << "end of f" << endl;
	return x;
}
/*
c语言中，static有两个作用，hidden和persistent
c++中，static仅可实现persistent，hidden由public等实现
	全局变量的对象构造函数在main之前调用
				析构函数在main之后
	static修饰成员变量，则成员变量是全局的。
		class内部是声明而非定义，没有给该变量分配空间，所以在调用全局成员变量前要在某个cpp定义int A::i;
			在定义一个对象前，即可通过类：：成员 来修改静态成员变量
			在定义i时，前面不可加static，因为类的成员变量可被其他文件访问。
		构造函数不可用初始化列表形式初始化，因为静态成员变量仅可在定义的地方被初始化
		访问public的静态成员变量/函数时，可以	类名::成员变量/函数
		静态成员函数不可调用非静态成员变量/函数
		this表示当前对象，所以	类::静态成员变量时无this
*/
int main()
{
	HowMany h;
	h.print("after construction of h");
	HowMany h2 = 10;
	HowMany h3 = h;//HowMany h3(h);
	HowMany h4 = f(h);
	h.print("after call to f()");

}