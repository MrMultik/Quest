#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "");
    std::string intPart, fracPart;
    std::cout << "Введите целую часть числа (без знака точки): ";
    if (!(std::cin >> intPart)) {
        std::cerr << "Ошибка ввода." << std::endl;
        return 1;
    }
    std::cout << "Введите дробную часть числа (только цифры): ";
    if (!(std::cin >> fracPart)) {
        std::cerr << "Ошибка ввода." << std::endl;
        return 1;
    }

    // Составляем строку вида "intPart.fracPart"
    std::string combined = intPart + "." + fracPart;

    try {
        double value = std::stod(combined);
        std::cout << "Составленное double-число: " << value << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка при преобразовании в double: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
