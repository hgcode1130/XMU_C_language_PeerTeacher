#include <stdio.h>
#include <string.h>
#include <cmath>
int main() {
  int n, k;
  char input[101];
  scanf("%d %d", &n, &k); // 读取n和k
  scanf("%s", input);     // 读取输入序列

  int sum = 0, num = 0, factor = 1;
  for (int i = n - 1; i >= 0; i--) {
    num += (input[i] - '0') * factor;
    factor *= 10;

    if (factor == 10 * k || i == 0) { // 每k位进行一次折叠
      sum += num;
      num = 0;
      factor = 1;
    }
  }

  // 输出最终的k位结果
  int result[10], idx = 0;
  do {
    result[idx++] = sum % (int)pow(10, k);
    sum /= (int)pow(10, k);
  } while (sum > 0);

  for (int i = idx - 1; i >= 0; i--) {
    printf("%0*d", k, result[i]);
  }
  printf("\n");

  return 0;
}
