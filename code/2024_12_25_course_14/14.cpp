#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char s[80];
  struct Node *next;
} Node;

// (1) 计算t(s)值
int t(char *s) {
  int count[128] = {0};
  char min_char = 127;
  for (int i = 0; s[i]; i++) {
    count[s[i]]++;
    if (s[i] < min_char)
      min_char = s[i];
  }
  return count[min_char];
}

// (2) 复制链表
Node *ex(Node *A, int n) {
  Node *B = NULL, *tail = NULL, *current = A;
  int count = 0;

  while (current) {
    if (count++ == n) {
      Node *new_node = (Node *)malloc(sizeof(Node));
      strcpy(new_node->s, current->s);
      new_node->next = NULL;

      if (!B)
        B = tail = new_node;
      else {
        tail->next = new_node;
        tail = new_node;
      }
    }
    current = current->next;
  }
  return B;
}

int main() {
  Node *A = NULL, *tail = NULL;
  int n;
  char buffer[80];

  // 输入链表
  while (scanf("%s", buffer) != EOF) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->s, buffer);
    new_node->next = NULL;

    if (!A)
      A = tail = new_node;
    else {
      tail->next = new_node;
      tail = new_node;
    }
  }

  printf("Enter n: ");
  scanf("%d", &n);

  Node *B = ex(A, n);

  // 输出链表B
  Node *current = B;
  while (current) {
    printf("%s -> ", current->s);
    current = current->next;
  }
  printf("NULL\n");

  return 0;
}
