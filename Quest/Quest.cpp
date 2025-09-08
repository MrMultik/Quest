#include <iostream>
#include <cmath>

int main()
{
    setlocale(LC_ALL, "Russian");
    float a, b, c;
    std::cout << "Введите коэффициенты a, b, c: ";
    std::cin >> a >> b >> c;

    if (a == 0)
    {
        std::cout << "Это не квадратное уравнение!" << std::endl;
    }
    else
    {
        float discriminant = b * b - 4 * a * c;

        if (discriminant > 0)
        {
            float x1 = (-b + std::sqrt(discriminant)) / (2 * a);
            float x2 = (-b - std::sqrt(discriminant)) / (2 * a);
            std::cout << "Два корня: " << x1 << " и " << x2 << std::endl;
        }
        else if (discriminant == 0)
        {
            float x = -b / (2 * a);
            std::cout << "Один корень: " << x << std::endl;
        }
        else
        {
            std::cout << "Комплексные корни не поддерживаются!" << std::endl;
        }
    }

    return 0;
}