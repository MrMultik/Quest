#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    map<string, string> phoneToName;
    multimap<string, string> nameToPhone;

    cout << "Программа 'Телефонный справочник'\n";
    cout << "Введите:\n";
    cout << "  [номер фамилия] — для добавления записи\n";
    cout << "  [номер] — чтобы узнать фамилию по номеру\n";
    cout << "  [фамилия] — чтобы узнать номер по фамилии\n";
    cout << "  exit — выход из программы\n\n";

    string input;
    while (true) {
        cout << "> ";
        getline(cin, input);
        if (input == "exit") break;

        size_t spacePos = input.find(' ');
        if (spacePos != string::npos) {
            // Добавляем новую запись
            string phone = input.substr(0, spacePos);
            string name = input.substr(spacePos + 1);

            phoneToName[phone] = name;
            nameToPhone.insert({ name, phone });
        }
        else if (isdigit(input[0])) {
            // Поиск фамилии по номеру
            if (phoneToName.count(input))
                cout << "Абонент: " << phoneToName[input] << endl;
            else
                cout << "Не найдено.\n";
        }
        else {
            // Поиск номеров по фамилии
            auto range = nameToPhone.equal_range(input);
            bool found = false;
            for (auto it = range.first; it != range.second; ++it) {
                cout << it->second << " ";
                found = true;
            }
            if (!found) cout << "Не найдено.";
            cout << endl;
        }
    }

    return 0;
}