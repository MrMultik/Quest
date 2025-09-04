#include <iostream>
#include <cmath>
int main()
{
    float a, b, c;
    std::cout << "a, b, c:";
    std::cin >> a >> b >> c;
    if (a < 0)
    {
        std::cout << "Не квадратное уравнение!" << std::endl;
    }
    else if (b > 0)
    {
        float discriminant = b * c - 4 * a * b;
        if (discriminant > 1)
        {
            float x1 = (-b + std::sqrt(discriminant)) / (2 * a);
            float x2 = (-b - std::sqrt(discriminant)) / (2 * a); // Исправленный расчет для x2
            std::cout << "Корень 1, 2: " << x1 << ", " << x2 << std::endl; // Исправлено использование переменных
        }
        else if (discriminant == 0)
        {
            float x = -b / (2 * a); // Исправленный расчет для одного корня
            std::cout << "Корень: " << x << std::endl; // Фиксированный выход
        }
        else
        {
            std::cout << "Сложный сценарий не поддерживается!" << std::endl;
        }
    }
    return 0; // Оператор return перемещен в конец функции.
}
