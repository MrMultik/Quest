﻿#include <iostream>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 10;
    int b = 20;

    swap(&a, &b);

    std::cout << a << " " << b << std::endl; // 20 10
    return 0;
}