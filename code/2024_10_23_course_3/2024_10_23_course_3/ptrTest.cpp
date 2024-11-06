//#include <stdio.h>
//演示实例
//int main()
//{
//	int n = 10;
//	char* pc = (char*)&n;//int *
//	int* pi = &n;
//	printf("%p\n", &n);
//	printf("%p\n", pc);
//	printf("%p\n", pc + 1);
//	printf("%p\n", pi);
//	printf("%p\n", pi + 1);
//	return 0;
//}
//演示实例
//#include <stdio.h>
//int main()
//{
//	int n = 0x11223344;
//	char* pc = (char*)&n;
//	printf("%d\n", *pc);
//	n = 0x11223344;
//	int* pi = &n;
//	printf("%d\n", *pi);
//	//*pc = 0; //重点在调试的过程中观察内存的变化。
//	//*pi = 0; //重点在调试的过程中观察内存的变化。
//	return 0;
//}
