#include <iostream>
#include <queue>

using ll = long long;

int main() {
    setlocale(LC_ALL, "");
    std::priority_queue<ll> max5;
    long long total_count = 0;

    std::cout << "Введите числа. Команды:\n"
        << "-1 -> вывести 5-е по возрастанию\n"
        << "-2 -> завершить\n";

    while (true) {
        ll x;
        if (!(std::cin >> x)) {
            std::cerr << "Ошибка ввода.\n";
            return 1;
        }
        if (x == -2) {
            std::cout << "Завершение.\n";
            break;
        }
        else if (x == -1) {
            if (total_count < 5) {
                std::cerr << "Недостаточно чисел для 5-го по возрастанию.\n";
            }
            else {
                std::cout << "5-е по возрастанию: " << max5.top() << "\n";
            }
        }
        else {
            total_count++;
            if ((int)max5.size() < 5) {
                max5.push(x);
            }
            else if (x < max5.top()) {
                max5.pop();
                max5.push(x);
            }
        }
    }

    return 0;
}
