#include <iostream>
#include <string>
#include <clocale>
#include "tools.h"

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "=== Симулятор операции ===\n";
    std::cout << "Команды:\n";
    std::cout << "  scalpel x1 y1 x2 y2\n";
    std::cout << "  hemostat x y\n";
    std::cout << "  tweezers x y\n";
    std::cout << "  suture x1 y1 x2 y2 (конец операции)\n";

    std::string cmd;
    Point scalpelA{}, scalpelB{};
    bool started = false;

    while (true) {
        std::cout << "> ";
        if (!(std::cin >> cmd)) break;

        if (cmd == "scalpel") {
            scalpelA = readPoint();
            scalpelB = readPoint();
            scalpel(scalpelA, scalpelB);
            started = true;
        }
        else if (cmd == "hemostat") {
            Point p = readPoint();
            if (!started) std::cout << "Внимание: операция ещё не начата (scalpel).\n";
            hemostat(p);
        }
        else if (cmd == "tweezers") {
            Point p = readPoint();
            if (!started) std::cout << "Внимание: операция ещё не начата (scalpel).\n";
            tweezers(p);
        }
        else if (cmd == "suture") {
            Point a = readPoint();
            Point b = readPoint();
            suture(a, b);
            if (started && (a == scalpelA) && (b == scalpelB)) {
                std::cout << "Операция успешно завершена.\n";
                break;
            }
            else {
                std::cout << "Шов наложен, но точки не совпадают с начальным разрезом.\n";
            }
        }
        else {
            std::cout << "Неизвестная команда: " << cmd << std::endl;
            // Очистить остаток строки если надо
        }
    }

    return 0;
}