#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool is_valid_ipv4(const string& ip) {
    int dots = 0;
    string part;

    for (size_t i = 0; i <= ip.size(); i++) {
        if (i == ip.size() || ip[i] == '.') {
            if (part.empty()) return false; // две точки подряд или точка в начале/конце
            if (part.size() > 1 && part[0] == '0') return false; // ведущий ноль
            for (char c : part) if (!isdigit(c)) return false; // посторонние символы
            int num = stoi(part);
            if (num < 0 || num > 255) return false;
            part.clear();
            dots++;
        }
        else {
            part += ip[i];
        }
    }

    return dots == 4; // должно быть ровно 4 числа
}

int main() {
    string ip;
    cout << "Enter IP address: ";
    cin >> ip;

    if (is_valid_ipv4(ip)) {
        cout << "Valid" << endl;
    }
    else {
        cout << "Invalid" << endl;
    }

    return 0;
}
