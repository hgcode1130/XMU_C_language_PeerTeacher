// #include <stdio.h>
// int main() {
//   char str1[] = "hello bit.";
//   char str2[] = "hello bit.";
//   char *str3 = "hello bit.";
//   char *str4 = "hello bit.";
//   //数组名一般有三种情况
//   //1. 数组名作为左值，表示数组的首元素的地址
//   //2. 跟指针一样
//   if (str1 == str2)
//     printf("str1 and str2 are same\n");
//   else
//     printf("str1 and str2 are not same\n");

//   if (str3 == str4)
//     printf("str3 and str4 are same\n");
//   else
//     printf("str3 and str4 are not same\n");
//   return 0;
// }

// #include <stdio.h>
// int main() {
// //int * p
//   int arr[10] = {0};
//   printf("arr = %p\n", arr);
//   printf("&arr= %p\n", &arr);
//   //其实是一个int * 类型的指针
//   printf("arr+1 = %p\n", arr + 1); // 4
//   //其实它一次性移动了整个数组的大小
//   printf("&arr+1= %p\n", &arr + 1);//0x28 32 + 8 = 40
//   return 0;
// }

// #include <stdio.h>
// void print_arr1(int arr[3][5], int row, int col) {
//   int i = 0 , j;
//   for (i = 0; i < row; i++) {
//     for (j = 0; j < col; j++) {
//       printf("%d ", arr[i][j]);
//     }
//     printf("\n");
//   }
// }

// void print_arr2(int (*arr)[5], int row, int col) {
//   int i = 0 , j;
//   for (i = 0; i < row; i++) {
//     for (j = 0; j < col; j++) {
//       printf("%d ", arr[i][j]);
//     }
//     printf("\n");
//   }
// }
// int main() {
//   int arr[3][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//   // 1 2 3 4 5
//   // 6 7 8 9 10
//   //0 0 0 0 0
//   print_arr1(arr, 3, 5);
//   // 数组名arr，表示首元素的地址
//   // 但是二维数组的首元素是二维数组的第一行
//   // 所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址
//   // 可以数组指针来接收
//   print_arr2(arr, 3, 5);
//   return 0;
// }

// // 代码1
// (*(void (*)())0)();
// // 代码2
// void (*signal(int, void (*)(int)))(int);

// #include <stdio.h>
// int add(int a, int b) { return a + b; }
// int sub(int a, int b) { return a - b; }
// int mul(int a, int b) { return a * b; }
// int div(int a, int b) { return a / b; }
// int main() {
//   int x, y;
//   int input = 1;
//   int ret = 0;
//   int (*p[5])(int x, int y) = {0, add, sub, mul, div}; // 转移表
//   while (input) {
//     printf("*************************\n");
//     printf(" 1:add 2:sub \n");
//     printf(" 3:mul 4:div \n");
//     printf("*************************\n");
//     printf("请选择：");
//     scanf("%d", &input);
//     if ((input <= 4 && input >= 1)) {
//       printf("输入操作数：");
//       scanf("%d %d", &x, &y);
//       ret = (*p[input])(x, y);
//     } else
//       printf("输入有误\n");
//     printf("ret = %d\n", ret);
//   }
//   return 0;
// }