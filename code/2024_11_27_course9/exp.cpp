// #include <stdio.h>
// #include <string.h>
// int main() {
//   // 字符串及其相关函数。
//   // n
//   // strcpy()函数：将一个字符串拷贝到另一个字符串中。
//   // strcat()函数：将一个字符串追加到另一个字符串的尾部。
//   // strcmp()函数：比较两个字符串是否相等。
//   // strlen()函数：计算字符串的长度。
//   // strstr()函数：查找一个字符串是否包含另一个字符串。
//   //
//   size_t n = 0;
//   // strcpy("hello","world");

//   // void * dest , int num , size_t size
//   // 注意是字节
//   int a[10];
//   // 00000001000000010000000100000001
//   // 1111111111111111111111111111
//   // 如果想要赋值成无穷大
//   // 3f3f3f3f
//   //memset(a, 0x3f, sizeof(a));
//   // 负无穷
//   // memset(a, -0x3f, sizeof(a));
//   //memset(a, -1, sizeof a);
//   for (int i = 0; i < 10; i++) {
//     printf("%d ", a[i]);
//   }
//   return 0;
// }

// size_t错误示例
//  #include <stdio.h>
//  #include <string.h>
//  int main() {
//    const char *str1 = "abcdef";
//    const char *str2 = "bbb";
//    if (strlen(str2) - strlen(str1) > 0) {
//      printf("str2>str1\n");
//    } else {
//      printf("srt1>str2\n");
//    }
//    return 0;
//  }

/* strncat example */
// #include <stdio.h>
// #include <string.h>
// int main() {
//   char str1[20];
//   char str2[20];
//   strcpy(str1, "To be ");
//   strcpy(str2, "or not to be");
//   strncat(str1, str2, 6);
//   puts(str1);
//   return 0;
// }

/* strncmp example */
// #include <stdio.h>
// #include <string.h>
// int main() {
//   char str[][5] = {"R2D2", "C3PO", "R2A6"};
//   int n;
//   puts("Looking for R2 astromech droids...");
//   for (n = 0; n < 3; n++)
//     if (strncmp(str[n], "R2xx", 2) == 0) {
//       printf("found %s\n", str[n]);
//     }
//   return 0;
// }

// strstr example
//********** Begin **********
//  #include <stdio.h>
//  #include <string.h>

// int main() {
//   char t[1005] = {0};
//   char s[1005] = {0};
//   gets(t);
//   gets(s);

//   char *p = strstr(t, s);
//   int len = strlen(s);
//   int len2 = strlen(t);
//   int i;
//   while (p != NULL) {
//     char *m = p + len;
//     for (i = 0; *(m + i) != 0; i++) {
//       *(p + i) = *(m + i);
//     }
//     *(p + i) = *(m + i);
//     p = strstr(t, s);
//   }
//   printf("%s\n", t);

//   return 0;
// }

//********** End ********** 1

/* strtok example */
// #include <stdio.h>
// #include <string.h>
// int main() {
//   char str[] = "- This, a sample string.";
//   char *pch;
//   printf("Splitting string \"%s\" into tokens:\n", str);
//   pch = strtok(str, " ,.-");
//   while (pch != NULL) {
//     printf("%s\n", pch);
//     pch = strtok(NULL, " ,.-");
//   }
//   printf("%s\n",str);
//   return 0;
// }

// 请在下方编写代码
#include <stdio.h>
const int N = 15;
// 当前来到了第几位，从哪个数开始枚举
int vis[N]; // 表示数字i有没有被选择过
int path[N];
int n, m;
// 我正在选第u个数且从start开始枚举
void dfs(int u, int start) {
  if (u == m + 1) {
    for (int i = 1; i <= m; i++)
      printf("%d ", path[i]);
    printf("\n");
    return;
  }
  for (int i = start; i <= n; i++) {
    if (!vis[i]) {
      vis[i] = 1;
      path[u] = i;
      dfs(u + 1, i + 1);
      vis[i] = 0;
      path[i] = 0;
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  dfs(1, 1);
  return 0;
}