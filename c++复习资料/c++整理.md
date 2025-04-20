# C++知识点整理

## 第一章：C++语言基础

```mermaid
graph TD
    A[C++基本概念] --> B[对象]
    A --> C[类]
    A --> D[封装]
    A --> E[继承]
    A --> F[多态]

    B --> G[数据]
    B --> H[操作]

    C --> I[抽象]
    C --> J[模板]

    D --> K[信息隐藏]
    D --> L[接口设计]

    E --> M[基类]
    E --> N[派生类]

    F --> O[重载]
    F --> P[虚函数]
```

```mermaid
graph LR
    A[程序开发流程] --> B[编辑]
    B --> C[编译]
    C --> D[连接]
    D --> E[运行]

    F[程序设计步骤] --> G[需求分析]
    G --> H[系统设计]
    H --> I[编程实现]
    I --> J[测试与调试]
    J --> K[运行与维护]
```

## 第二章：C++数据类型与基本语法

## 2.1 数据类型概述

### 基本数据类型

<style>
.type-table {
    border-collapse: collapse;
    width: 100%;
    margin: 20px 0;
}
.type-table th, .type-table td {
    border: 1px solid #ddd;
    padding: 8px;
    text-align: left;
}
.type-table th {
    background-color: #f2f2f2;
}
.type-table tr:nth-child(even) {
    background-color: #f9f9f9;
}
</style>

<table class="type-table">
<tr>
    <th>类型</th>
    <th>大小</th>
    <th>范围</th>
    <th>示例</th>
</tr>
<tr>
    <td>short int</td>
    <td>2字节</td>
    <td>-32,768 到 32,767</td>
    <td>short x = 100;</td>
</tr>
<tr>
    <td>int</td>
    <td>4字节</td>
    <td>-2,147,483,648 到 2,147,483,647</td>
    <td>int y = 1000;</td>
</tr>
<tr>
    <td>long long int</td>
    <td>8字节</td>
    <td>-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807</td>
    <td>long long z = 1000000000LL;</td>
</tr>
<tr>
    <td>float</td>
    <td>4字节</td>
    <td>±3.4E±38 (7位精度)</td>
    <td>float f = 3.14f;</td>
</tr>
<tr>
    <td>double</td>
    <td>8字节</td>
    <td>±1.7E±308 (15位精度)</td>
    <td>double d = 3.14159;</td>
</tr>
<tr>
    <td>char</td>
    <td>1字节</td>
    <td>-128 到 127或0 到 255</td>
    <td>char c = 'A';</td>
</tr>
<tr>
    <td>bool</td>
    <td>1字节</td>
    <td>true 或 false</td>
    <td>bool flag = true;</td>
</tr>
<tr>
    <td>void</td>
    <td>0字节</td>
    <td>无值</td>
    <td>void* ptr;</td>
</tr>
</table>

### 示例代码

```cpp
#include <iostream>
using namespace std;

int main() {
    // 数值类型示例
    int integer = 42;
    float floating = 3.14f;
    double precise = 3.14159265359;

    // 字符类型示例
    char character = 'A';
    bool boolean = true;

    // 类型转换示例
    int converted = static_cast<int>(floating);

    cout << "整数: " << integer << endl;
    cout << "浮点数: " << floating << endl;
    cout << "双精度: " << precise << endl;
    cout << "字符: " << character << endl;
    cout << "布尔值: " << boolalpha << boolean << endl;
    cout << "转换后的值: " << converted << endl;

    return 0;
}
```

### 思考题

#### 1. 类型溢出问题

**问题**：给定以下代码，输出结果是什么？为什么？

```cpp
unsigned char x = 255;
x++;
cout << (int)x << endl;
```

**解答**：

- 输出结果为 0
- 原因：unsigned char 的范围是 0-255，当 x 为 255 时再自增，会发生溢出，循环回到 0
- 这展示了数据类型的循环特性和处理溢出的重要性

#### 2. 浮点数精度问题

**问题**：为什么下面的代码可能输出 false？

```cpp
float a = 0.1f;
if (a + a + a == 0.3f)
    cout << "true" << endl;
else
    cout << "false" << endl;
```

**解答**：

- 输出为 false
- 原因：浮点数在计算机中是以二进制形式存储的，某些十进制小数无法精确表示
- 0.1 在二进制中是无限循环小数，存储时会发生截断，累加时误差会放大
- 在需要精确计算时，应使用定点数或专门的数值计算库

#### 3. 挑战思考题：类型转换与优先级

**问题**：分析以下代码的输出结果：

```cpp
int i = 1;
char c = 'A';
double d = 0.5;
cout << sizeof(i + c) << " " << sizeof(c + d) << " " << sizeof(1.0f + 2.0) << endl;
```

**解答**：

- 输出：4 8 8
- 解释：
  1. `i + c`：char 会被提升为 int，结果是 int 类型（4 字节）
  2. `c + d`：char 先转为 int，然后与 double 运算，结果是 double（8 字节）
  3. `1.0f + 2.0`：float 与 double 运算，结果是 double（8 字节）
- 这展示了 C++中的类型提升规则和算术转换的优先级

### 进阶知识点

1. **类型限定符**：

   - const：声明常量
   - volatile：告诉编译器变量可能会被外部修改
   - mutable：允许 const 对象中的成员被修改

2. **数据对齐**：
   - 不同的数据类型有不同的对齐要求
   - 可以使用#pragma pack()控制对齐
   - 影响结构体的大小和内存访问效率

```cpp
// 数据对齐示例
struct Example1 {
    char c;     // 1字节
    int i;      // 4字节
    double d;   // 8字节
};

struct Example2 {
    double d;   // 8字节
    int i;      // 4字节
    char c;     // 1字节
};

cout << sizeof(Example1) << endl; // 输出可能大于13
cout << sizeof(Example2) << endl; // 输出可能不同于Example1
```

```mermaid
graph TD
    A[C++数据类型] --> B[简单数据类型]
    A --> C[构造数据类型]
    A --> D[抽象数据类型]

    B --> B1[整数]
    B --> B2[实数]
    B --> B3[字符]
    B --> B4[逻辑]
    B --> B5[空值]

    C --> C1[指针]
    C --> C2[引用]
    C --> C3[数组]
    C --> C4[结构体]
    C --> C5[枚举]
    C --> C6[联合]

    D --> D1[类]
    D --> D2[派生类]
```

c. 常量：字面常量、符号常量
（1）字面常量：整数类型、实数类型、字符类型、字符串
（2）符号常量
d. 操作符：
（1）算数操作符：+、-、\*、/、%、++、--
（2）关系操作符：>、<、>=、<=、==、!=
（3）逻辑操作符：&&、｜｜、! （注意短路求值）
（4）逻辑位操作符：～（按位取反）、&（按位取与）、｜（按位取或）、^（按位异或）（x^a）^a=x、<<、>>
（5）赋值操作符：（简单）=、（复合）+=、-=、\*=、/=、%=、&=、｜=、^=、<<=、>>=
（6）其他操作符：?: 、 ， 、sizeof

```mermaid
graph LR
    A[操作符] --> B[算数操作符]
    A --> C[关系操作符]
    A --> D[逻辑操作符]
    A --> E[位操作符]
    A --> F[赋值操作符]
    A --> G[其他操作符]

    B --> B1["+, -, *, /, %"]
    C --> C1[">, <, >=, <="]
    D --> D1["&&, ||, !"]
    E --> E1["&, |, ^, ~"]
    F --> F1["=, +=, -="]
    G --> G1["?:, sizeof"]
```

e. 类型转换：
（1）隐式类型转换
（2）显式类型转换
f. 优先级与结合性：
（1）优先级：决定表达式中各种不同的运算符起作用的优先次序
（2）结合性：在相邻的两个运算符的具有同等优先级时，决定表达式的结合方向

## 第三章：

a. 语句
（1）顺序执行语句：表达式语句、复合语句、空语句
（2）选择执行语句：if 语句、switch 语句
（3）循环执行语句：while 语句、while-do 语句、for 语句
（4）无条件转移语句：goto 语句、break 语句、continue 语句、return 语句
b. C++内部不能定义局部常量

```mermaid
flowchart TD
    A[程序控制结构] --> B[顺序结构]
    A --> C[选择结构]
    A --> D[循环结构]
    A --> E[跳转语句]

    C --> C1[if语句]
    C --> C2[switch语句]

    D --> D1[while循环]
    D --> D2[do-while循环]
    D --> D3[for循环]

    E --> E1[break]
    E --> E2[continue]
    E --> E3[return]
    E --> E4[goto]
```

## 第四章：

a. 子程序间的数据传递
（1）值传递
（2）地址传递
（3）引用传递
b. 参数传递
（1）值传递
（2）地址传递
（3）引用传递
c. 全局变量与局部变量
d. 命名空间：在一个命名空间中定义的全局标识符，其作用域为该命名空间
e. 作用域与生存期
（1）作用域：局部作用域、全局作用域、文件作用域、函数作用域、函数原型作用域、命名空间作用域、类作用域
（2）生存期：静态生存期、自动生存期、动态生存期

1. static：全局变量改为文件作用域、局部变量具有静态生存期
2. auto：局部变量默认、形参
3. register：使用频率高的局部变量
4. 静态生存期：static 局部变量、全局变量
5. 自动生存期：auto 局部变量、函数形参、register
6. 动态生存期：new、delete、malloc、free
   （3）内存空间：静态数据区、代码区、栈区、堆区
   1）静态数据区（大小固定）：全局变量、static 局部变量、某些常量
   2）代码区（大小固定）：函数代码
   3）栈区：auto 局部变量、函数形参、函数调用有关信息
   4）堆区：动态变量内存分配

```mermaid
graph TD
    A[作用域] --> B[局部作用域]
    A --> C[全局作用域]
    A --> D[文件作用域]
    A --> E[函数作用域]
    A --> F[命名空间作用域]
    A --> G[类作用域]

    H[内存空间] --> I[静态数据区]
    H --> J[代码区]
    H --> K[栈区]
    H --> L[堆区]

    I --> I1[全局变量]
    I --> I2[静态变量]

    K --> K1[局部变量]
    K --> K2[函数参数]

    L --> L1[动态分配]
    L --> L2[new/delete]
```

f. 内联函数
（1）内联函数：在函数定义中的返回值类型之前加上关键字 inline
（2）作用：建议编译程序把该函数的函数体展开到调用点，避免函数调用的开销，提高函数调用的效率

## 第五章：

a. 数组类型（排序）
（1）定义：一种由固定多个同类型的具有一定次序关系的元素所构成的复合数据类型
（2）排序：
1）冒泡排序法：

```CPP
void BubbleSort(int arr[], int n)
{
	for (int i = 0; n - i - 1; j++)
	{
		if (arr[j] > arr[j + 1])
		{
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
	}
}
```

2）选择排序法：

```CPP
void selectSort(int a[], int len)
{
	int minindex, temp;
	for(int i = 0;len-1;i++)
	{
		minindex = i;
		for(int j = i+1; j<len; j++)
		{
			if(a[j]<a[minindex])
			minindex = j;
		}
		temp = a[i];
		a[i] = a[minindex];
		a[minindex] = temp;
	}
}
```

3）快速排序法：

```CPP
void quickSort(int a[], int low ,int high)
{
	if(low<high) //判断是否满足排序条件，递归的终止条件
	{
	int i = low, j = high;
	int x = a[low];
	//将待排序数组的第一个元素作为哨兵，将数组划分为大于哨兵以及小于哨兵的两部分

	while(i<j)
	{
	while(i<j && a[j] >= x) j--;
	//从最右侧元素开始，如果比哨兵大，那么它的位置就正确，然后判断前一个元素，直到不满足条件

			if(i<j) a[i++] = a[j];

	//把不满足位次条件的那个元素值赋值给第一个元素，（也即是哨兵元素，此时哨兵已经保存在 x 中，不会丢失）并把 i 的加 1

			while(i<j && a[i] <= x) i++;

	//换成左侧下标为 i 的元素开始与哨兵比较大小，比其小，那么它所处的位置就正确，然后判断后一个，直到不满足条件

			if(i<j) a[j--] = a[i];

	//把不满足位次条件的那个元素值赋值给下标为 j 的元素，（下标为 j 的元素已经保存到前面，不会丢失）并把 j 的加 1
	}

				a[i] = x;

	//完成一次排序，把哨兵赋值到下标为 i 的位置，即前面的都比它小，后面的都比它大
	quickSort(a, low ,i-1);
	//递归进行哨兵前后两部分元素排序，low,high 的值不发生变化，i 处于中间
	quickSort(a, i+1 ,high);
}
```

b. 枚举类型（enum）
c. 结构体（struct）
d. 联合类型（union）
e. 指针类型
（1）定义：指针是内存地址的抽象表示
（2）（void*）输出字符串内存首地址
（3）const
1）const int* p：指向常量的指针（不能改变元素的值）
2）int\* const p：指针类型的常量（可以改变所指变量的值，但不能改变指针本身的值）
3）const 成员函数只能获取对象的状态，而不能改变对象的状态
（4）交换参数
1）多级指针

```cpp
void swap(int **x,int **y)
{
	int *t;
	t=*x;
	*x=*y;
	*y=t;
}
```

2）指针加引用

```cpp
void swap(int _&x,int _&y)
{
	int *t;
	t=x;x=y;y=t;
}
3）引用
void swap(int &x,int &y)
{
	int t;
	t=x;x=y;y=t;
}
```

4）指针

```cpp
void swap (int *x, int *y)
{
	int t;
	t = *x;
	*x = *y;
	\*y = t;
}
```

f. 链表
g. 引用类型
（1）作为参数：相当于别名，可提高参数传递效率
（2）引用：直接访问，参数是一个变量的名字
指针：间接访问，参数是一个变量的地址
（3）不能再引用其他变量

## 第六章：

a. 面向对象
（1）面向对象程序设计：把程序构造成由若干对象组成，每个对象由一些数据以及对这些数据所能实施的操作构成；对对象的操作是通过向包含数据的对象发消息来实现的；对象的特征由相应的类来描述，一个类所描述的对象特征可以从其他类继承；
（2）对象：对象构成了面向对象程序的基本计算单位，它由数据、操作以及对外接口构成；
（3）通信：通信是指对象间的消息传递，它是引起面向对象程序进行计算的唯一方式；
（4）类：类描述了一组具有相同特征的对象；
（5）类的成员：数据成员和成员函数；
（6）继承：继承是指对象的一部分特征描述可以从其他的类获得；（派生类&基类）
（7）对象和类体现了数据抽象和封装的概念。类是对象的集合；对象是类的实例。
（8）多态性：某一论域中的一个元素存在多种解释；不同的对象调用相同名称的函数。
（9）绑定：指对多态元素确定使用的过程，即确定对多态元素的某个使用是多态元素的哪一种形式；（静态绑定&动态绑定）
（10）类属性：指一个程序实体能对多种类型的数据进行操作或描述的特性。通过指针和函数模板实现类属函数；通过联合类型和类模板实现类属类型。

```mermaid
classDiagram
    class Object {
        +data
        +operations()
        +interface()
    }

    class Class {
        +attributes
        +methods()
    }

    class Inheritance {
        +baseClass
        +derivedClass
    }

    class Polymorphism {
        +virtualFunctions()
        +overloading()
        +overriding()
    }

    Class --> Object : describes
    Inheritance --> Class : extends
    Polymorphism --> Object : applies to
```

```mermaid
graph TD
    A[构造函数调用顺序] --> B[基类构造函数]
    B --> C[成员对象构造函数]
    C --> D[派生类构造函数]

    E[析构函数调用顺序] --> F[派生类析构函数]
    F --> G[成员对象析构函数]
    G --> H[基类析构函数]
```

```mermaid
graph LR
    A[对象生命周期] --> B[构造]
    B --> C[初始化]
    C --> D[使用]
    D --> E[析构]

    F[内存管理] --> G[栈对象]
    F --> H[堆对象]
    G --> I[自动管理]
    H --> J[手动管理]
```

b. 数据成员
（1）数据成员初始化：赋值函数、构造函数、成员初始化表
（2）信息隐藏：public、private、protected
c. 对象
（1）创建方式：直接方式、间接方式
1）直接方式：A a；
2）间接方式：A \*p; p=new A; delete p;
（2）如果变量的类型为类，则称变量为对象；
（3）this 指针
d. 构造函数
（1）定义：在对象类中定义或声明的与类同名、无返回值类型的成员函数；
（2）在创建对象时，构造函数自动调用；创建之后不能再调用；
（3）调用顺序：基类->对象->派生类
（4）构造函数不能被派生类继承
e. 拷贝构造函数
（1）被调用情况：
1）用类的一个已知的对象去初始化该类的另一个对象时；
2）函数的形参是类的对象，调用函数进行形参和实参的结合时；
3）函数的返回值是类的对象，函数执行完返回调用者。
（2）调用顺序：基类的拷贝构造函数 -> 成员对象的拷贝构造函数 -> 派生类的拷贝构造函数
（3）深拷贝与浅拷贝示例：

```cpp
class DeepCopyExample {
private:
    int* data;
    size_t size;
public:
    // 构造函数
    DeepCopyExample(size_t n) : size(n) {
        data = new int[size];
        for(size_t i = 0; i < size; i++) {
            data[i] = i;
        }
    }

    // 深拷贝构造函数
    DeepCopyExample(const DeepCopyExample& other) : size(other.size) {
        data = new int[size];
        for(size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // 析构函数
    ~DeepCopyExample() {
        delete[] data;
    }

    // 防止浅拷贝引起的问题，实现赋值运算符
    DeepCopyExample& operator=(const DeepCopyExample& other) {
        if(this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for(size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
};
```

（4）思考题：为什么需要检查自赋值？不检查会发生什么问题？

f. 转移构造函数
（1）参数类型：右值引用类型，要求只能是临时对象或要消亡的对象
（2）意义：用即将消亡的对象去初始化另一个同类的对象
（3）函数：

```cpp
A(A&& x)
{
    p=x.p;
    x.p=NULL;
}
```

（4）完整的移动语义实现示例：

```cpp
class SmartArray {
private:
    int* data;
    size_t size;

public:
    // 构造函数
    SmartArray(size_t n) : size(n) {
        data = new int[n];
    }

    // 移动构造函数
    SmartArray(SmartArray&& other) noexcept
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
    }

    // 移动赋值运算符
    SmartArray& operator=(SmartArray&& other) noexcept {
        if(this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    // 析构函数
    ~SmartArray() {
        delete[] data;
    }

    // 禁用拷贝构造和拷贝赋值
    SmartArray(const SmartArray&) = delete;
    SmartArray& operator=(const SmartArray&) = delete;
};

// 使用示例
SmartArray createArray(size_t size) {
    return SmartArray(size);  // 返回临时对象，触发移动构造
}
```

（5）思考题：为什么移动构造函数和移动赋值运算符要标记为 noexcept？

g. 析构函数
（1）在对象消亡前，在系统收回它所占的内存空间之前，会自动调用对象类的析构函数。
（2）数组：delete []p; （[] 必须写，否则只调用数组第一个对象的析构函数）
（3）调用顺序：派生类->对象->基类
h. const
（1）若对象为 const 类，则调用函数必为 const 函数
i. 静态数据成员
（1）类的静态成员：静态数据成员、静态成员函数
（2）静态数据成员往往在类的外部给出定义并进行初始化。
（3）类定义中的静态数据成员对于该类的所有对象只存在一个拷贝。
（4）静态成员函数只能访问静态成员；
（5）静态成员函数没有隐藏的 this 指针（因为静态成员函数对静态数据成员操作，静态数据成员只有一个拷贝）
（6）私有的
j. 友元
（1）在 C++的一个类定义中，可以指定某个全局函数、某个其他类或某个其他类的某个成员函数能直接访问该类的私有和保护成员，分别称为：友元函数、友元类、友元类成员函数，统称友元。
（2）作用：提高对象私有数据成员的访问效率
（3）友元函数和运算符重载结合示例：

```cpp
class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 声明友元函数
    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);
    friend std::ostream& operator<<(std::ostream& out, const Complex& c);

    // 友元类
    friend class ComplexMatrix;

    // 特定类的友元成员函数
    friend void Calculator::compute(const Complex& c);
};

// 友元函数实现
Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

Complex operator*(const Complex& a, const Complex& b) {
    return Complex(
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    );
}

std::ostream& operator<<(std::ostream& out, const Complex& c) {
    out << c.real;
    if(c.imag >= 0) out << "+";
    out << c.imag << "i";
    return out;
}
```

（4）思考题：为什么 operator<<需要作为友元函数而不是成员函数？

k. 操作符重载进阶
（1）类型转换运算符重载：

```cpp
class Fraction {
private:
    int num, den;
public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) {}

    // 类型转换运算符
    explicit operator double() const {
        return static_cast<double>(num) / den;
    }

    // 转换构造函数
    explicit Fraction(double d) {
        den = 1000;
        num = static_cast<int>(d * den);
        // 这里应该添加约分逻辑
    }
};
```

（2）思考题：

1. 为什么要使用 explicit 关键字？
2. 如果去掉 explicit 会产生什么问题？
3. 如何实现一个安全的分数类，使其能够自动约分并防止除零错误？

### 第七章：继承与派生

继承是面向对象编程（OOP）中的一个核心概念，它允许我们创建一个新的类（派生类），继承自已有的类（基类）。这样可以重用已有代码，增加新的功能或对旧功能进行扩展。

#### 示例与内容扩充：

- **继承与访问权限**：

  - **public** 成员可以被所有类访问。
  - **protected** 成员只能在基类和派生类中访问。
  - **private** 成员只能在基类内部访问。

- **虚函数**与**函数重写**：
  - 基类中的虚函数（`virtual`）允许派生类重写（override）该方法。

#### 示例代码：

```cpp
#include <iostream>

class Base {
public:
    int publicMember = 10;
    virtual void display() {
        std::cout << "Base class display() called" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() override { // Function overriding
        std::cout << "Derived class display() called" << std::endl;
    }
};

int main() {
    Base *basePtr = new Derived();
    basePtr->display(); // Calls Derived class's display due to dynamic binding
    delete basePtr;
    return 0;
}
```

```mermaid
classDiagram
    class Base {
        +publicMember
        #protectedMember
        -privateMember
        +virtualMethod()
    }

    class Derived {
        +overriddenMethod()
        +newMethod()
    }

    class MultipleInheritance {
        +method1()
        +method2()
    }

    Base <|-- Derived : inherits
    Base <|-- MultipleInheritance : inherits
    OtherBase <|-- MultipleInheritance : inherits
```

### 第八章：多态性

多态性是 OOP 的一个重要特性，它允许对象以不同的形式表现。多态性主要分为两种：编译时多态（静态多态）和运行时多态（动态多态）。

#### 示例与内容扩充：

- **编译时多态**：

  - **函数重载**（函数名相同，但参数不同）。
  - **运算符重载**（自定义运算符行为）。

- **运行时多态**：
  - 使用**虚函数**来实现动态绑定。
  - **纯虚函数**和**抽象类**提供接口但不提供实现，必须由派生类实现。

#### 示例代码：

```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

int main() {
    Shape *shape1 = new Circle();
    Shape *shape2 = new Rectangle();
    shape1->draw();
    shape2->draw();
    delete shape1;
    delete shape2;
    return 0;
}
```

```mermaid
graph TD
    A[多态性] --> B[编译时多态]
    A --> C[运行时多态]

    B --> D[函数重载]
    B --> E[运算符重载]

    C --> F[虚函数]
    C --> G[纯虚函数]

    F --> H[动态绑定]
    G --> I[抽象类]
```

### 第九章：函数模板与类模板

模板是 C++中泛型编程的基础。它允许在定义函数或类时不指定类型，而是通过模板参数来动态指定类型。

#### 示例与内容扩充：

- **函数模板**：用于定义可以处理不同数据类型的函数。
- **类模板**：用于定义可以处理不同数据类型的类。

#### 示例代码：

```cpp
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
class Box {
private:
    T value;
public:
    Box(T val) : value(val) {}
    T getValue() {
        return value;
    }
};

int main() {
    // Using function template
    cout << "Sum: " << add(3, 4) << endl;

    // Using class template
    Box<int> intBox(10);
    cout << "Box value: " << intBox.getValue() << endl;
    return 0;
}
```

```mermaid
graph TD
    A[模板] --> B[函数模板]
    A --> C[类模板]

    B --> D[模板参数]
    B --> E[实例化]

    C --> F[成员函数模板]
    C --> G[静态成员]

    D --> H[类型参数]
    D --> I[非类型参数]

    E --> J[显式实例化]
    E --> K[隐式实例化]
```

```mermaid
classDiagram
    class Container~T~ {
        +T data
        +Container(T value)
        +T getValue()
        +void setValue(T value)
    }

    class Stack~T~ {
        -T[] elements
        -int top
        +push(T element)
        +T pop()
        +bool isEmpty()
    }

    Container~T~ <|-- Stack~T~ : extends
```

### 第十章：异常处理

异常处理是 C++中的一种机制，用于处理程序中的错误或不正常的行为，以保证程序能够在出现异常时做出适当的反应。

#### 示例与内容扩充：

- **try-catch 语句**：用来捕获并处理异常。
- **throw 语句**：用来抛出异常。
- **标准异常与自定义异常**：标准异常如`std::out_of_range`，也可以自定义异常类。

#### 示例代码：

```cpp
#include <iostream>
#include <stdexcept>
using namespace std;

void divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero");
    }
    cout << "Result: " << a / b << endl;
}

int main() {
    try {
        divide(10, 0);
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
```

```mermaid
graph TD
    A[异常处理] --> B[try块]
    A --> C[throw语句]
    A --> D[catch块]

    B --> E[保护代码]
    C --> F[抛出异常]
    D --> G[捕获异常]

    H[异常类型] --> I[标准异常]
    H --> J[自定义异常]

    K[异常传播] --> L[函数调用栈]
    K --> M[异常规范]
```

```mermaid
sequenceDiagram
    participant 主程序
    participant try块
    participant catch块
    participant 异常对象

    主程序->>try块: 执行代码
    try块->>异常对象: 发生异常
    异常对象->>catch块: 抛出异常
    catch块->>主程序: 处理异常
    主程序->>主程序: 继续执行
```

### 第十一章：输入输出流

C++的输入输出流提供了丰富的功能，能够处理来自控制台、文件、内存等多种不同来源的输入输出。

#### 示例与内容扩充：

- **文件操作**：可以使用`ifstream`、`ofstream`进行文件的读写操作。
- **格式化输出**：通过流操纵符来控制输出格式。

#### 示例代码：

```cpp
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    // Writing to a file
    ofstream outFile("example.txt");
    outFile << "Hello, World!" << endl;
    outFile.close();

    // Reading from a file
    ifstream inFile("example.txt");
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    // Using manipulators for formatted output
    double pi = 3.14159265359;
    cout << fixed << setprecision(2) << pi << endl;
    return 0;
}
```

```mermaid
graph LR
    A[I/O流] --> B[输入流]
    A --> C[输出流]

    B --> D[istream]
    B --> E[ifstream]
    B --> F[istringstream]

    C --> G[ostream]
    C --> H[ofstream]
    C --> I[ostringstream]

    J[操纵符] --> K[格式化输出]
    J --> L[状态标志]
```

```mermaid
graph TD
    A[文件操作] --> B[打开文件]
    A --> C[读写操作]
    A --> D[关闭文件]

    B --> E[文件模式]
    C --> F[文本模式]
    C --> G[二进制模式]

    H[流状态] --> I[good]
    H --> J[eof]
    H --> K[fail]
    H --> L[bad]
```

### 第十二章：STL 标准模板库

STL (Standard Template Library) 是 C++标准库的核心组件，提供了一系列通用的模板类和函数。

#### 12.1 容器

STL 提供了多种容器类型，每种都有其特定的用途和性能特征。

```mermaid
graph TD
    A[STL容器] --> B[顺序容器]
    A --> C[关联容器]
    A --> D[容器适配器]

    B --> E[vector]
    B --> F[list]
    B --> G[deque]

    C --> H[set/multiset]
    C --> I[map/multimap]
    C --> J[unordered_set/map]

    D --> K[stack]
    D --> L[queue]
    D --> M[priority_queue]
```

##### 示例代码：

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    // Vector示例
    vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);

    // Map示例
    map<string, int> scores;
    scores["Alice"] = 95;
    scores["Bob"] = 89;

    // 使用算法
    sort(vec.begin(), vec.end());

    return 0;
}
```

#### 12.2 迭代器

迭代器提供了访问容器元素的统一接口。

迭代器类别：

- 输入迭代器
- 输出迭代器
- 前向迭代器
- 双向迭代器
- 随机访问迭代器

#### 12.3 算法

STL 提供了大量的通用算法，可以在不同的容器上使用。

常用算法示例：

```cpp
#include <algorithm>
#include <vector>

vector<int> nums = {3, 1, 4, 1, 5, 9};

// 排序
sort(nums.begin(), nums.end());

// 查找
auto it = find(nums.begin(), nums.end(), 4);

// 计数
int count = count_if(nums.begin(), nums.end(),
    [](int x) { return x > 3; });
```

#### 思考题

1. **容器选择问题**
   问题：在以下场景中，应该选择哪种 STL 容器，为什么？

- 需要频繁在序列中间插入元素
- 需要快速的随机访问
- 需要按键值对存储且要求键值有序

答案：

- list（双向链表），因为它的中间插入操作时间复杂度为 O(1)
- vector，支持随机访问迭代器，访问时间复杂度为 O(1)
- map，基于红黑树实现，可以保持键值有序，查找时间复杂度为 O(log n)

2. **算法复杂度分析**
   问题：分析以下代码的时间复杂度：

```cpp
vector<int> v(n);
for(auto it = v.begin(); it != v.end(); ++it) {
    v.insert(it, *it);
}
```

答案：
时间复杂度为 O(n²)，因为 vector 的 insert 操作需要移动插入点后的所有元素，每次插入的时间复杂度为 O(n)，总共执行 n 次。

3. **进阶思考题：迭代器失效**
   问题：以下代码可能存在什么问题？如何修复？

```cpp
vector<int> nums = {1, 2, 3, 4, 5};
for(auto it = nums.begin(); it != nums.end(); ++it) {
    if(*it % 2 == 0) {
        nums.erase(it);
    }
}
```

答案：

- 问题：迭代器失效。当使用 erase 删除元素时，会导致迭代器失效。
- 修复方案：

```cpp
vector<int> nums = {1, 2, 3, 4, 5};
for(auto it = nums.begin(); it != nums.end();) {
    if(*it % 2 == 0) {
        it = nums.erase(it);
    } else {
        ++it;
    }
}
```

#### 性能对比图

```mermaid
graph LR
    A[容器性能对比] --> B[插入操作]
    A --> C[删除操作]
    A --> D[查找操作]

    B --> E[vector: O(n)]
    B --> F[list: O(1)]
    B --> G[map: O(log n)]

    C --> H[vector: O(n)]
    C --> I[list: O(1)]
    C --> J[map: O(log n)]

    D --> K[vector: O(n)]
    D --> L[list: O(n)]
    D --> M[map: O(log n)]
```

### 期末复习要点

1. **基础概念**

   - 面向对象的三大特性：封装、继承、多态
   - 内存管理和 RAII 概念
   - 模板和泛型编程

2. **重点掌握**

   - 智能指针的使用场景和实现原理
   - 移动语义和完美转发
   - STL 容器的选择和使用
   - 并发编程基础

3. **常见面试题**

   - 解释虚函数表的工作原理
   - 描述 STL allocator 的作用
   - 比较深拷贝和浅拷贝的区别
   - 解释 RAII 的概念和应用

4. **实践建议**
   - 编写模板类时考虑异常安全
   - 使用现代 C++特性提高代码质量
   - 注意性能优化和内存管理
   - 保持代码的可维护性和可读性


### 补充内容

#### 13.2 Lambda 表达式

Lambda 表达式允许我们创建匿名函数对象，使代码更简洁和灵活。

##### 语法与示例：

```cpp
#include <algorithm>
#include <vector>

std::vector<int> numbers = {1, 2, 3, 4, 5};

// 基本语法：[捕获列表](参数列表) -> 返回类型 {函数体}
auto sum = [](int a, int b) -> int { return a + b; };

// 使用捕获列表
int multiplier = 10;
auto multiply = [multiplier](int x) { return x * multiplier; };

// mutable关键字允许修改捕获的变量
auto counter = [count = 0]() mutable { return ++count; };
```

##### 思考题：Lambda 表达式捕获

问题：以下代码可能存在什么问题？

```cpp
std::vector<std::function<int()>> functors;
for(int i = 0; i < 5; i++) {
    functors.push_back([&i]() { return i; });
}
```

答案：

- 这段代码存在悬挂引用的问题
- 当循环结束后，i 已经超出了作用域
- 正确的做法是使用值捕获：`[i]`而不是`[&i]`


