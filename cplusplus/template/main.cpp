#include "MyVector.h"

template <class T>
//仅对紧随其后的第一个函数或类有效
void myswap(T& x, T& y)
//如果无T类型的形参，则写为 void myswap(void){}
//调用时，void myswap<int>();
{
	T temp = x;
	x = y;
	y = temp;
}
template <class T>
void sort(MyVector<T>& arr)
{
	const size_t last = arr.size() - 1;
	for (int i = 0; i < last; i++)
	{
		for (int j = last; i < j; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				myswap(arr[j], arr[j - 1]);
			}
		}
	}
}
int main()
{
 	int x = 1, y = 2;
	myswap( x,  y);
	//myswap(int,double)	error
	cout << x << endl << y << endl;
	/*
	MyVector<int> vi(4);
	vi[0] = 4;
	vi[1] = 3;
	vi[2] = 7;
	vi[3] = 1;
	sort(vi);
	*/
	try
	{
		MyVector<int> v(3);
		cout << v[7] << endl;
	}
		catch (VectorIndexError& e)
	{
		e.diagnostic();
	}
	/*
	catch (...)//捕捉所有异常
	{
		cout << "The exception stops here!" << endl;
		//throw;	表示把刚刚catch到的异常扔出去
	}
	*/
	cout << "Control is here after exception";
	return 0;
}
//void abc(int a):throw(err1,err2){}最多有俩错误