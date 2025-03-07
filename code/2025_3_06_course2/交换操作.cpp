void swap1(int &a, int &b) {
    // 实现引用的交换
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b) {
    // 实现指针的交换
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap3(int *&a, int *&b) {
    // 实现指针引用的交换
    int *temp = a;
    a = b;
    b = temp;
}
