#include <iostream>
#include <cstring>

bool substr(const char* str, const char* sub) {
    int n = strlen(str);
    int m = strlen(sub);

    if (m > n) return false;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && str[i + j] == sub[j]) {
            j++;
        }
        if (j == m) return true; // нашли подстроку
    }
    return false;
}

int main() {
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";

    std::cout << std::boolalpha; // вывод true/false вместо 1/0
    std::cout << substr(a, b) << " " << substr(a, c) << std::endl;
    // true false

    return 0;
}
