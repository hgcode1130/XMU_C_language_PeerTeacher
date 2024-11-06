//#include <stdio.h>
//void Swap1(int x, int y)
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//	printf("function内部x:%d y:%d\n", x, y);
//}
////函数的参数
////实际参数（实参）：
////真实传给函数的参数，叫实参。实参可以是：常量、变量、表达式、函数等。无论实参是何种类
////型的量，在进行函数调用时，它们都必须有确定的值，以便把这些值传送给形参。
////形式参数（形参）：
////形式参数是指函数名后括号中的变量，因为形式参数只有在函数被调用的过程中才实例化（分配
////内存单元），所以叫形式参数。形式参数当函数调用完成之后就自动销毁了。因此形式参数只在
////函数中有效。
////上面Swap1和Swap2函数中的参数 x，y，px，py 都是形式参数。在main函数中传给Swap1的num1，
////num2和传给Swap2函数的& num1，& num2是实际参数。
////这里我们对函数的实参和形参进行分析：
//void Swap2(int* px, int* py)
//{
//	int tmp = 0;
//	tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//int main()
//{
//	int num1 = 1;
//	int num2 = 2;
//	Swap1(num1, num2);
//	printf("Swap1::num1 = %d num2 = %d\n", num1, num2);
//	Swap2(&num1, &num2);
//	printf("Swap2::num1 = %d num2 = %d\n", num1, num2);
//	return 0;
//}