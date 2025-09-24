#include <iostream>
#include <string>

enum note {
    DO = 1,   // 1 << 0
    RE = 2,   // 1 << 1
    MI = 4,   // 1 << 2
    FA = 8,   // 1 << 3
    SOL = 16,  // 1 << 4
    LA = 32,  // 1 << 5
    SI = 64   // 1 << 6
};

int main() {
	setlocale(LC_ALL, "");
    std::string chord;
    std::cout << "Введите аккорд (строка цифр 1..7), например 1234 или 63: ";
    if (!(std::cin >> chord)) {
        std::cerr << "Ошибка ввода." << std::endl;
        return 1;
    }

    int mask = 0;
    for (size_t i = 0; i < chord.size(); ++i) {
        char c = chord[i];
        if (c >= '1' && c <= '7') {
            int idx = c - '1'; // 0..6
            mask |= (1 << idx);
        }
        else {
            // Игнорируем другие символы
        }
    }

    bool first = true;
    if (mask & DO) { if (!first) std::cout << " "; std::cout << "DO"; first = false; }
    if (mask & RE) { if (!first) std::cout << " "; std::cout << "RE"; first = false; }
    if (mask & MI) { if (!first) std::cout << " "; std::cout << "MI"; first = false; }
    if (mask & FA) { if (!first) std::cout << " "; std::cout << "FA"; first = false; }
    if (mask & SOL) { if (!first) std::cout << " "; std::cout << "SOL"; first = false; }
    if (mask & LA) { if (!first) std::cout << " "; std::cout << "LA"; first = false; }
    if (mask & SI) { if (!first) std::cout << " "; std::cout << "SI"; first = false; }

    std::cout << std::endl;
    return 0;
}
