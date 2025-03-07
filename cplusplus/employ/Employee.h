#include <iostream>
using namespace std;

class Employee
{
//成员函数在声明时即写出body，则为内联函数
public:
	Employee(const string& name, const string& ssn);
	const string& get_name() const;
	/*
	const修饰变量时，必须在初始化时给值，除非前有extern(声明某个const的全局变量)
	不能用const修饰cin进来的相关数据，因为编译时刻未知(extern也一样)
	指针	
		char* const q="abc";	q是const,可改指向内容，不可q++
		const char *p="ABC";	p指向内容是const，不能通过指针修改指向内容
	类
		Person p1("Fred",200);
		const Person *p=&p1;		p指向内容，即对象是const
		Person const* p=&p1;		对象是const
		Person *const p=&p1;		指针是const
		const在*前面则对象是const；在*后面则指针是const

		const修饰对象时，对象所有值不可修改；但有些成员函数会修改成员变量
		所以在成员函数后跟const，保证改成员函数不修改任何成员变量（声明和定义都要重复）;
		成员函数有无const可构成重载，默认调用有const的
		如果成员变量为const，则必须用初始化列表初始化
	
	字符串在代码段，默认const；	定义时如果以指针形式定义则会出错；以数组形式定义则会拷贝到堆栈
	函数
		void f(const int* x);	传入指针，但保证不会修改指针指向内容
	*/
	void print(ostream& out) const;
	void print(ostream& out, const string& msg) const;
protected:
	string m_name;
	string m_ssn;
};

Employee::Employee(const string& name, const string& ssn) :m_name(name), m_ssn(ssn) {}

inline const string& Employee::get_name() const
{
	return m_name;
}

inline void Employee::print(ostream& out) const
{
	out << m_name << endl;
	out << m_ssn << endl;
}

inline void Employee::print(ostream& out, const string& msg) const
{
	out << msg << endl;
	print(out);		//避免代码复制
}