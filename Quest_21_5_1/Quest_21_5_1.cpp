#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <locale>
using namespace std;

struct Payment {
    string name;
    string surname;
    string date;
    double amount;
};

int main() {
    setlocale(LC_ALL, "Russian");

    string filePath = "C:\\Users\\User\\Desktop\\C\\Test\\Quest\\Quest_21_5_1\\vedomost.txt";
    vector<Payment> list;
    string command;

    cout << "Введите команду (list - показать, add - добавить): ";
    cin >> command;

    if (command == "list") {
        ifstream file(filePath);
        if (!file.is_open()) {
            cout << "Файл не найден. Создаю новый..." << endl;
            ofstream newFile(filePath);
            newFile.close();
            return 0;
        }

        Payment p;
        while (file >> p.name >> p.surname >> p.date >> p.amount) {
            list.push_back(p);
        }
        file.close();

        cout << "Ведомость выплат:\n";
        for (auto& x : list) {
            cout << x.name << " " << x.surname << " | Дата: " << x.date << " | Сумма: " << x.amount << " руб.\n";
        }
    }
    else if (command == "add") {
        ofstream file(filePath, ios::app);
        Payment p;
        cout << "Введите имя: ";
        cin >> p.name;
        cout << "Введите фамилию: ";
        cin >> p.surname;
        cout << "Введите дату (ДД.ММ.ГГГГ): ";
        cin >> p.date;
        cout << "Введите сумму: ";
        cin >> p.amount;

        file << p.name << " " << p.surname << " " << p.date << " " << p.amount << endl;
        file.close();
        cout << "Запись добавлена!" << endl;
    }
    else {
        cout << "Неизвестная команда.\n";
    }
}
