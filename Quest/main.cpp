#include <iostream>
#include <string>

std::string encrypt_caesar(const std::string& text, int shift) {
    std::string result;
    shift = shift % 26; // если сдвиг больше алфавита

    for (char c : text) {
        if (c >= 'A' && c <= 'Z') {
            result += char((c - 'A' + shift + 26) % 26 + 'A');
        }
        else if (c >= 'a' && c <= 'z') {
            result += char((c - 'a' + shift + 26) % 26 + 'a');
        }
        else {
            result += c; // не буквы не шифруем
        }
    }
    return result;
}

int main1() {
    std::string text;
    int shift;

    std::cout << "Enter text: ";
    std::getline(std::cin, text);

    std::cout << "Enter shift: ";
    std::cin >> shift;

    std::string encrypted = encrypt_caesar(text, shift);
    std::cout << "Encrypted: " << encrypted << std::endl;

    return 0;
}
