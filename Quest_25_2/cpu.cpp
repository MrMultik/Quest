#include <iostream>
#include "cpu.h"
#include "ram.h"

void cpu_compute() {
    long long sum = 0;
    for (int i = 0; i < 8; ++i) sum += ram_read(i);
    std::cout << "CPU: сумма = " << sum << std::endl;
}