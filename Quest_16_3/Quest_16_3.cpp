#include <iostream>
#include <sstream>
#include <string>

int main() {
	setlocale(LC_ALL, "");
    std::string buffer;
    std::cout << "Введите выражение в виде <число><операция><число> (без пробелов), например 12.5+3.4" << std::endl;
    std::cout << "Ввод: ";
    if (!std::getline(std::cin, buffer) || buffer.empty()) {
        std::cerr << "Нет ввода." << std::endl;
        return 1;
    }

    std::stringstream ss(buffer);
    double a, b;
    char op;

    // Извлекаем первое число, оператор, второе число
    if (!(ss >> a)) {
        std::cerr << "Ошибка чтения первого числа." << std::endl;
        return 1;
    }

    if (!(ss >> op)) {
        std::cerr << "Ошибка чтения оператора." << std::endl;
        return 1;
    }

    if (!(ss >> b)) {
        std::cerr << "Ошибка чтения второго числа." << std::endl;
        return 1;
    }

    double result = 0.0;
    bool ok = true;
    switch (op) {
    case '+': result = a + b; break;
    case '-': result = a - b; break;
    case '*': result = a * b; break;
    case '/':
        if (b == 0.0) {
            std::cerr << "Ошибка: деление на ноль." << std::endl;
            ok = false;
        }
        else result = a / b;
        break;
    default:
        std::cerr << "Неподдерживаемая операция: " << op << std::endl;
        ok = false;
    }

    if (ok) {
        std::cout << "Результат: " << result << std::endl;
        return 0;
    }
    else {
        return 1;
    }
}
