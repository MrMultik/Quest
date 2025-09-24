#include <iostream>
#include <cstdio>
#include <cmath>

int main() {
	setlocale(LC_ALL, "");
    double speed = 0.0;
    const double EPS = 0.01;
    const double MAX_SPEED = 150.0;
    char speed_str[64];

    std::cout << "Спидометр запущен. Вводите дельту скорости (км/ч)." << std::endl;

    do {
        double delta;
        std::cout << "Speed delta:";
        if (!(std::cin >> delta)) {
            std::cerr << "Ошибка ввода. Завершение." << std::endl;
            return 1;
        }

        speed += delta;

        // Ограничиваем скорость диапазоном [0, MAX_SPEED]
        if (speed > MAX_SPEED) speed = MAX_SPEED;
        if (speed < 0.0) speed = 0.0;

        // Форматируем в строку с одной цифрой после точки
        std::sprintf(speed_str, "%.1f", speed);

        std::cout << "Speed: " << speed_str << std::endl;

        // продолжаем пока скорость больше 0 с точностью EPS
    } while (speed > EPS);

    std::cout << "Машина остановлена (speed <= 0.01)." << std::endl;
    return 0;
}