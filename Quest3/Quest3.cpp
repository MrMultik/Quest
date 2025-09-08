#include <iostream>
#include <string>
#include <sstream>

bool isValidOctet(const std::string& part) {
    if (part.empty()) return false;
    if (part.size() > 1 && part[0] == '0') return false; // ведущие нули
    for (char c : part) {
        if (!isdigit(c)) return false;
    }
    int num = std::stoi(part);
    return num >= 0 && num <= 255;
}

bool validateIP(const std::string& ip) {
    std::stringstream ss(ip);
    std::string part;
    int count = 0;

    while (std::getline(ss, part, '.')) {
        if (!isValidOctet(part)) return false;
        count++;
    }
    return count == 4;
}

int main() {
    std::string ip;
    std::cout << "Enter IP address: ";
    std::getline(std::cin, ip);

    if (validateIP(ip))
        std::cout << "Valid" << std::endl;
    else
        std::cout << "Invalid" << std::endl;

    return 0;
}
