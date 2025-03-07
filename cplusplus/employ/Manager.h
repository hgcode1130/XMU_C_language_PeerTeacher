#pragma once
#include "Employee.h"
/*造型
子类的对象可以被看作父类的对象，多出来的部分地址在后部分(upcast)    向上造型
downcast有风险
*/

class Manager :
    public Employee
{
public:
    Manager(const string& name, const string& ssn, const string& title = "Someone");
    const string title_name() const;
    const string& get_title() const;
    void print(ostream& out) const;     //与父类同名，则仅保留子类函数，父类函数隐藏；但是向上造型时，同名函数为父类函数;virtual时调用自身
private:
    string m_title;
};

Manager::Manager(const string& name, const string& ssn, const string& title) :
    Employee(name, ssn), m_title(title) {}

inline void Manager::print(ostream& out) const
{
    Employee::print(out);
    out << m_title << endl;
}
inline const string& Manager::get_title() const
{
    return m_title;
}
inline const string Manager::title_name() const
{
    return string(m_title + ": " + m_name);
}