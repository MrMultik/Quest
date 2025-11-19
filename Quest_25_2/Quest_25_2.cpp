#include <iostream>
#include <string>
#include <clocale>

#include "cpu.h"
#include "ram.h"
#include "disk.h"
#include "gpu.h"
#include "kbd.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "=== Симулятор ПК ===\n";
    std::cout << "Команды: input display sum save load exit\n";

    std::string cmd;
    while (true) {
        std::cout << "> ";
        if (!(std::cin >> cmd)) break;

        if (cmd == "input") kbd_input();
        else if (cmd == "display") gpu_display();
        else if (cmd == "sum") cpu_compute();
        else if (cmd == "save") disk_save();
        else if (cmd == "load") disk_load();
        else if (cmd == "exit") break;
        else std::cout << "Неизвестная команда\n";
    }
    return 0;
}