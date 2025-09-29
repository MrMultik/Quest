#include <iostream>

void evendigits(long long n, int& ans) {
    if (n == 0) return; // базовый случай

    int digit = n % 10; // последняя цифра
    if (digit % 2 == 0) ans++; // проверяем на чётность

    evendigits(n / 10, ans); // рекурсия: убираем последнюю цифру
}

int main() {
    int ans = 0;
    evendigits(9223372036854775806LL, ans);
    std::cout << ans << std::endl; // 10
    return 0;
}