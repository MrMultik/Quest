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

    unsigned char signature[4];
    file.read(reinterpret_cast<char*>(signature), 4);

    if (file.gcount() == 4 &&
        signature[0] == 0x89 &&
        signature[1] == 'P' &&
        signature[2] == 'N' &&
        signature[3] == 'G') {
        std::cout << "Файл является PNG-изображением." << std::endl;
    }
    else {
        std::cout << "Файл НЕ является PNG-изображением." << std::endl;
    }

    file.close();
    return 0;
}