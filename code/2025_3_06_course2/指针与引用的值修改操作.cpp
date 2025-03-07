void modify1(int &a) {
    // 实现引用的值修改
    a = 20;
}

void modify2(int *a) {
    // 实现指针的值修改
    *a = 25;
}

void modify3(int *&a) {
    // 实现指针引用的值修改
    *a = 50;
}
