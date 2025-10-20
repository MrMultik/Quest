#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

struct ATM {
    int bills[6]; // номиналы: 100, 200, 500, 1000, 2000, 5000
};

int main() {
    setlocale(LC_ALL, "Russian");

    const int nominals[6] = { 100, 200, 500, 1000, 2000, 5000 };
    ATM atm{};
    string path = "C:\\Users\\User\\Desktop\\C\\Test\\Quest\\Quest_20_4\\atm.bin";

    // Загружаем данные, если есть
    ifstream fin(path, ios::binary);
    if (fin.is_open()) {
        fin.read(reinterpret_cast<char*>(&atm), sizeof(ATM));
        fin.close();
        cout << "Банкомат загружен из файла.\n";
    }
    else {
        cout << "Файл не найден. Банкомат пуст.\n";
    }

    while (true) {
        int total = 0;
        for (int i = 0; i < 6; i++) total += atm.bills[i] * nominals[i];
        cout << "\nТекущее состояние:\n";
        for (int i = 0; i < 6; i++)
            cout << nominals[i] << " руб. — " << atm.bills[i] << " шт.\n";
        cout << "Всего денег: " << total << " руб.\n";

        cout << "\nВведите команду (+ пополнить, - снять, q выйти): ";
        char cmd;
        cin >> cmd;
        if (cmd == 'q') break;

        if (cmd == '+') {
            srand(time(nullptr));
            int totalBills = 0;
            for (int i = 0; i < 6; i++) totalBills += atm.bills[i];
            while (totalBills < 1000) {
                int index = rand() % 6;
                atm.bills[index]++;
                totalBills++;
            }
            cout << "Банкомат пополнен.\n";
        }
        else if (cmd == '-') {
            int sum;
            cout << "Введите сумму для снятия: ";
            cin >> sum;
            int remaining = sum;
            for (int i = 5; i >= 0; i--) {
                while (atm.bills[i] > 0 && remaining >= nominals[i]) {
                    atm.bills[i]--;
                    remaining -= nominals[i];
                }
            }
            if (remaining == 0) cout << "Выдано " << sum << " руб.\n";
            else cout << "Невозможно выдать сумму!\n";
        }
    }

    ofstream fout(path, ios::binary);
    fout.write(reinterpret_cast<char*>(&atm), sizeof(ATM));
    fout.close();
    cout << "Состояние банкомата сохранено.\n";
    return 0;
}