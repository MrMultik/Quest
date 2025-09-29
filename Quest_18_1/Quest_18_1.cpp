#include <iostream>
#include <vector>

void swapvec(std::vector<int>& v, int* arr) {
    for (size_t i = 0; i < v.size(); i++) {
        int temp = v[i];
        v[i] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    std::vector<int> a = { 1,2,3,4 };
    int b[] = { 2,4,6,8 };

    swapvec(a, b);

    for (int i = 0; i < 4; i++)
        std::cout << a[i];
    std::cout << std::endl;

    for (int i = 0; i < 4; i++)
        std::cout << b[i];
    std::cout << std::endl;

    return 0;
}