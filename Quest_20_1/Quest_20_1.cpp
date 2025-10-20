#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    string firstName, lastName, date;
    double payment;

    cout << "Введите имя: ";
    cin >> firstName;
    cout << "Введите фамилию: ";
    cin >> lastName;
    cout << "Введите дату выплаты (ДД.ММ.ГГГГ): ";
    cin >> date;
    cout << "Введите сумму выплаты (в рублях): ";
    cin >> payment;

    ofstream file("C:\\Users\\User\\Desktop\\C\\Test\\Quest\\Quest_20_1\\payments.txt", ios::app);
    if (!file.is_open()) {
        cout << "Не удалось открыть файл для записи!" << endl;
        return 1;
    }

    file << firstName << " " << lastName << " " << date << " " << payment << endl;
    file.close();

    cout << "Запись успешно добавлена!" << endl;
    return 0;
}