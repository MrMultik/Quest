#include <fstream>
#include <iostream>
#include "disk.h"
#include "ram.h"

void disk_save() {
    std::ofstream f("data.txt");
    if (!f) { std::cout << "Disk: не удалось открыть data.txt для записи\n"; return; }
    for (int i = 0; i < 8; ++i) {
        f << ram_read(i) << (i == 7 ? "\n" : " ");
    }
    std::cout << "Disk: сохранено в data.txt\n";
}

void disk_load() {
    std::ifstream f("data.txt");
    if (!f) { std::cout << "Disk: data.txt не найден\n"; return; }
    for (int i = 0; i < 8; ++i) {
        int v; if (!(f >> v)) { std::cout << "Disk: ошибка чтения\n"; return; }
        ram_write(i, v);
    }
    std::cout << "Disk: загружено из data.txt\n";
}