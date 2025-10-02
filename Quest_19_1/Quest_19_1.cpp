#include <iostream>
#include <fstream>
#include <string>


void findWord(const std::string& filepath, const std::string& word) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cout << "Не удалось открыть файл!" << std::endl;
        return;
    }

    std::string w;
    int count = 0;
    while (file >> w) {
        if (w == word) count++;
    }

    std::cout << "Слово \"" << word << "\" встречается " << count << " раз(а)." << std::endl;
    file.close();
}

int main() {
	setlocale(LC_ALL, "Russian");
    std::string filepath = "C:\\Users\\User\\Desktop\\C\\Test\\Quest\\Faile\\words.txt";
    std::string word;
    std::cout << "Введите слово для поиска: ";
    std::cin >> word;

    findWord(filepath, word);
    return 0;
}
