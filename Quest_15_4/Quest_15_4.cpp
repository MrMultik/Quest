#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;

int main() {
    setlocale(LC_ALL, "");
    int n;
    std::cout << "Введите размер массива: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Ошибка размера.\n";
        return 1;
    }

    std::vector<ll> a(n);
    std::cout << "Введите элементы массива (отсортированные):\n";
    for (int i = 0; i < n; i++) {
        if (!(std::cin >> a[i])) {
            std::cerr << "Ошибка ввода.\n";
            return 1;
        }
    }

    if (!std::is_sorted(a.begin(), a.end())) {
        std::cerr << "Массив не отсортирован. Будет отсортирован.\n";
        std::sort(a.begin(), a.end());
    }

    int right = 0;
    while (right < n && a[right] < 0) right++;
    int left = right - 1;

    std::vector<ll> out;
    out.reserve(n);

    while (left >= 0 || right < n) {
        if (left < 0) {
            out.push_back(a[right++]);
        }
        else if (right >= n) {
            out.push_back(a[left--]);
        }
        else {
            if (std::abs(a[left]) <= std::abs(a[right])) {
                out.push_back(a[left--]);
            }
            else {
                out.push_back(a[right++]);
            }
        }
    }

    std::cout << "Результат:\n";
    for (int i = 0; i < n; i++) {
        std::cout << out[i];
        if (i + 1 < n) std::cout << ", ";
    }
    std::cout << "\n";
    return 0;
}
