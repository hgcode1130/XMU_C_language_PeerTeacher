#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    char name[32];
    int height;
} Guest;

// 比较函数，先按身高降序排列，若身高相等则按名字字典序升序
int compare(const void *a, const void *b) {
    Guest *guestA = (Guest *)a;
    Guest *guestB = (Guest *)b;

    if (guestA->height != guestB->height) {
      return guestB->height - guestA->height; // 按身高降序
    } else {
        return strcmp(guestA->name, guestB->name) > 0; // 按名字字典序升序
    }
}

int main() {
    int N;
    Guest guests[MAX];

    // 输入嘉宾数量
    scanf("%d", &N);

    // 输入嘉宾信息
    for (int i = 0; i < N; i++) {
        scanf("%s %d", guests[i].name, &guests[i].height);
    }

    // 按规则排序
    qsort(guests, N, sizeof(Guest), compare);

    // 对称排列
    Guest arrangement[MAX];
    int left = (N - 1) / 2; // 左侧起点
    int right = left + 1;   // 右侧起点

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            arrangement[left--] = guests[i]; // 奇数放在左边
        } else {
            arrangement[right++] = guests[i]; // 偶数放在右边
        }
    }

    // 输出排列结果
    printf("嘉宾的最终拍照顺序为:\n");
    for (int i = 0; i < N; i++) {
        printf("(%s, %d) ", arrangement[i].name, arrangement[i].height);
    }
    printf("\n");

    return 0;
}
