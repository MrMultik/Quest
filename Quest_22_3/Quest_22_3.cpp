#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isAnagram(const string& a, const string& b) {
    if (a.size() != b.size()) return false;

    map<char, int> freq;
    for (char c : a) freq[c]++;
    for (char c : b) {
        if (--freq[c] < 0)
            return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Программа проверки анаграмм\n";
    cout << "Введите две строки:\n";

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    if (isAnagram(s1, s2))
        cout << "Строки являются анаграммами.\n";
    else
        cout << "Строки не являются анаграммами.\n";

    return 0;
}