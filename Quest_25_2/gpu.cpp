#include <iostream>
#include "gpu.h"
#include "ram.h"

void gpu_display() {
    std::cout << "GPU: RAM = ";
    for (int i = 0; i < 8; ++i) {
        std::cout << ram_read(i) << (i == 7 ? "\n" : " ");
    }
}