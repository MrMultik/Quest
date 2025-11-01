#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    map<string, int> registry;
    string command;

    cout << "Программа 'Регистратура'\n";
    cout << "Введите фамилию для добавления или команду 'Next' для вызова пациента.\n";
    cout << "Введите 'exit' для завершения работы.\n\n";

    while (true) {
        cout << "> ";
        cin >> command;
        if (command == "exit") break;

        if (command == "Next") {
            if (registry.empty()) {
                cout << "Очередь пуста.\n";
                continue;
            }
            auto it = registry.begin(); // первая по алфавиту фамилия
            cout << "Вызывается: " << it->first << endl;
            if (--(it->second) == 0)
                registry.erase(it);
        }
        else {
            registry[command]++;
        }
    }

    return 0;
}