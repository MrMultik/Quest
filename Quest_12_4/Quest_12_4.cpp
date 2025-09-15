#include <iostream>
#include <sstream>
#include <string>

int main() {
	setlocale(LC_ALL, "");

    int numbers[15];

    std::cout << "Введите 15 целых положительных чисел через запятую:" << std::endl;

    std::string input;
    std::getline(std::cin, input);

    // Заменяем запятые на пробелы для удобства обработки
    for (char& c : input) {
        if (c == ',') {
            c = ' ';
        }
    }

    std::istringstream iss(input);
    for (int i = 0; i < 15; i++) {
        if (!(iss >> numbers[i])) {
            std::cout << "Ошибка ввода! Проверьте формат данных." << std::endl;
            return 1;
        }
    }

    int min = numbers[0];
    int actual_sum = 0;

    // Находим минимальное число и считаем сумму всех элементов
    for (int i = 0; i < 15; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
        actual_sum += numbers[i];
    }

    // Вычисляем ожидаемую сумму для 14 последовательных чисел
    int expected_sum = 0;
    for (int i = min; i < min + 14; i++) {
        expected_sum += i;
    }

    // Разница между фактической и ожидаемой суммой дает повторяющееся число
    int duplicate = actual_sum - expected_sum;

    std::cout << "Повторяющееся число: " << duplicate << std::endl;
    std::cout << "Начало последовательности (X): " << min << std::endl;

    return 0;
}