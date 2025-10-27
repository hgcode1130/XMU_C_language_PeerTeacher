#include <stdio.h>
// 固定头部结束
// 你的代码开始
void find_two_largest(int a[], int n, int *largest, int *second_largest) {

    *largest = -0x3f3f3f3f , *second_largest = -0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        if (a[i] >= *largest) {
            *second_largest = *largest;
            *largest = a[i];
        }
        else if(a[i] > *second_largest){
            *second_largest = a[i];
        }
    }
}
// 你的代码结束
// 固定尾部开始
int main() {
  int i, n, arr[100], largest, second_largest;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  find_two_largest(arr, n, &largest, &second_largest);
  printf("%d %d", largest, second_largest);
  return 0;
}