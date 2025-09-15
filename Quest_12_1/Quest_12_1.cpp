#include <iostream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "");

    const int SIZE = 10;
    string residents[SIZE];

    // Ввод фамилий
    for (int i = 0; i < SIZE; i++) {
        cin >> residents[i];
    }

    // Три запроса номера квартиры
    for (int i = 0; i < 3; i++) {
        int number;
        cin >> number;

        if (number >= 1 && number <= SIZE)
            cout << residents[number - 1] << endl; // индексация с 0
        else
            cout << "Некорректный номер квартиры" << endl;
    }

    return 0;
}
