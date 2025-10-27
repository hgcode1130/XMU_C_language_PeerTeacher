#include <stdio.h>
#include <string.h>
#define SIZE 50 /* 去掉多余的分号 */
struct Goods {
  char item[30];
  double price;
  int count;
};

void load(struct Goods a[]); /* 增加函数声明 */

int main() {
  struct Goods a[SIZE];
  char strtemp[30];
  int flag = 0; /* 初始化 flag */
  int i;

  load(a);              /* 修正数组传递 */
  scanf("%s", strtemp); /* 去掉 &，因为 strtemp 本身是指针 */

  for (i = 0; i < SIZE; i++) {
    if (strcmp(strtemp, a[i].item) == 0) { /* 使用 strcmp 比较字符串 */
      flag = 1;
      a[i].price *= 1.1; /* 修正价格增加逻辑 */
      printf("item is: %s\t", a[i].item);
      printf("price is: %lf\t", a[i].price);
      printf("count is: %d\n", a[i].count);
    }
  }
  if (!flag) /* 去掉多余的 '4' */
    printf("there is no such item!\n");

  return 0; /* 增加 return 0，表示程序正常结束 */
}

void load(struct Goods a[]) {
  FILE *fp;
  int i;

  if ((fp = fopen("d:\\data.dat", "rb")) ==
      NULL) { /* 修正文件路径，添加转义符 */
    printf("cannot open file\n");
    return;
  }
  for (i = 0; i < SIZE; i++) {
    if (fread(&a[i], sizeof(struct Goods), 1, fp) != 1) /* 传递 a[i] 的地址 */
      printf("file read error\n");
  }
  fclose(fp); /* 增加 fclose 关闭文件 */
  return;
}
