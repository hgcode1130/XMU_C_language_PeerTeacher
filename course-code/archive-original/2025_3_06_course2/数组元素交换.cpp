void swapByIndex1(int arr[], int i, int j) {
    // 实现数组元素的引用交换
    // swap(arr[i], arr[j]);
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void swapByIndex2(int *arr, int i, int j) {
    // 实现数组元素的指针交换
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}