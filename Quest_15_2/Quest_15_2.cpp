#include <iostream>
#include <vector>
#include <unordered_map>

using ll = long long;

int main() {
    setlocale(LC_ALL, "");
    int n;
    std::cout << "Введите размер массива: ";
    if (!(std::cin >> n) || n < 2) {
        std::cerr << "Ошибка: размер должен быть >= 2.\n";
        return 1;
    }

    std::vector<ll> a(n);
    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; i++) {
        if (!(std::cin >> a[i])) {
            std::cerr << "Ошибка ввода.\n";
            return 1;
        }
    }

    ll target;
    std::cout << "Введите результат (сумму): ";
    if (!(std::cin >> target)) {
        std::cerr << "Ошибка ввода.\n";
        return 1;
    }

    std::unordered_map<ll, int> seen;
    for (int i = 0; i < n; i++) {
        ll need = target - a[i];
        if (seen.count(need)) {
            std::cout << "Найдены числа: " << need << " и " << a[i] << "\n";
            return 0;
        }
        seen[a[i]] = i;
    }

    std::cerr << "Пара не найдена.\n";
    return 1;
}
