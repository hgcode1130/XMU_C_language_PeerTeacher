void add1(int &a, int& b, int c) {
    // 实现引用的增量操作
    a += c;
    b += c;
}

void add2(int *a, int* b, int c) {
    // 实现指针的增量操作
    *a += c;
    *b += c;
}

void add3(int *&a, int*& b, int c) {
    // 实现指针引用的增量操作
    *a += c;
    *b += c;
}
