#include <iostream>
#include <fstream>
#include <string>

int main() {
	setlocale(LC_ALL, "Russian");
    std::string filepath;
    std::cout << "Введите путь к файлу: ";
    std::getline(std::cin, filepath);

    std::ifstream file(filepath, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл!" << std::endl;
        return 1;
    }

    const size_t bufsize = 1024;
    char buffer[bufsize];
    while (file.read(buffer, bufsize) || file.gcount()) {
        std::cout.write(buffer, file.gcount());
    }

    file.close();
    return 0;
}