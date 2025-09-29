#include <iostream>

void reverse(int* arr) {
    int n = 10; // всегда 10 элементов
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

int main() {
    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };

    reverse(arr);

    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; // 9 8 7 6 5 4 3 2 1 0
    return 0;
}
