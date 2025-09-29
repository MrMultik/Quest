#include <iostream>

int ways(int n, int k = 3) {
    if (n == 0) return 1;   // один способ остаться на месте
    if (n < 0) return 0;    // нельзя попасть в отрицательную ступеньку

    int total = 0;
    for (int i = 1; i <= k; i++) {
        total += ways(n - i, k);  // пробуем все длины прыжков от 1 до k
    }
    return total;
}

int main() {
    std::cout << ways(3, 2) << std::endl; // 3
    std::cout << ways(4) << std::endl;    // при k=3 → 7
    return 0;
}