#include <iostream>
#include "kbd.h"
#include "ram.h"

void kbd_input() {
    std::cout << "KBD: введите 8 целых чисел через пробел: ";
    for (int i = 0; i < 8; ++i) {
        int v; std::cin >> v;
        ram_write(i, v);
    }
    std::cout << "KBD: записано в RAM\n";
}