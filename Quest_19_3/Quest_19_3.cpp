#include <iostream>
#include <fstream>
#include <string>

int main() {
	setlocale(LC_ALL, "Russian");
    std::string filepath = "C:\\Users\\User\\Desktop\\C\\Test\\Quest\\Faile\\vedomost.txt";

    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл!" << std::endl;
        return 1;
    }

    std::string name, surname, date;
    long long sum, total = 0, maxSum = 0;
    std::string maxName;

    while (file >> name >> surname >> sum >> date) {
        total += sum;
        if (sum > maxSum) {
            maxSum = sum;
            maxName = name + " " + surname;
        }
    }

    std::cout << "Общая сумма выплат: " << total << std::endl;
    std::cout << "Максимальную сумму получил: " << maxName << " (" << maxSum << ")" << std::endl;

    file.close();
    return 0;
}