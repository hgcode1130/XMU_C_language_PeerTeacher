#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define swap(a, b) { int t = a; a = b; b = t; }
int main() {
    int n, k;
    char sequence[101];

    // 输入n和k
    scanf("%d %d", &n, &k);
    // 输入编码序列
    scanf("%s", sequence);

    int length = strlen(sequence);
    int result = 0; // 存储最终结果
    bool f = true; // 用于翻转
    // 遍历编码序列
    for (int i = length - 1; i >= 0; i -= k , f^=1) {
      int st = max(i - k + 1, 0);
      int ed = i;
      int temp = 0;
      if (f) {
        for (int i = st; i <= ed; i++) {
          temp = temp * 10 + (sequence[i] - '0');
        }
      } else {
        for (int i = ed; i >= st; i--) {
          temp = temp * 10 + (sequence[i] - '0');
        }
      }
      //printf("%d ", temp);
      result += temp;
    }

    printf("%d\n", result % (int)pow(10 ,k)); // 输出结果
    return 0;
}
