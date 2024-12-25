#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Guest {
  char name[32];
  int height;
} Guest;

int compare(const void *a, const void *b) {
  Guest *g1 = (Guest *)a;
  Guest *g2 = (Guest *)b;
  if (g1->height != g2->height)
    return g2->height - g1->height;  // 身高降序
  return strcmp(g1->name, g2->name); // 名字字典序
}

void arrange(Guest guests[], int n) {
  int rows = n / 2 + n % 2;
  int center = rows / 2;
  int idx = 0;

  for (int i = 0; i < rows; i++) {
    int size = (i == center) ? (n - rows + 1) : (rows / 2);
    Guest row[size];
    int left = size / 2 - 1, right = size / 2;

    for (int j = 0; j < size; j++) {
      if (j % 2 == 0)
        row[right++] = guests[idx++];
      else
        row[left--] = guests[idx++];
    }

    for (int j = 0; j < size; j++) {
      printf("%s ", row[j].name);
    }
    printf("\n");
  }
}

int main() {
  int n;
  scanf("%d", &n);

  Guest guests[n];
  for (int i = 0; i < n; i++) {
    scanf("%s %d", guests[i].name, &guests[i].height);
  }

  qsort(guests, n, sizeof(Guest), compare);
  arrange(guests, n);

  return 0;
}
