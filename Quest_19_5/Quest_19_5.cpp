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

// Функция для создания файла
void createFile(const string& filePath) {
    ofstream file(filePath);
    if (file.is_open()) {
        cout << "Файл успешно создан: " << filePath << endl;
        
        // Можно сразу добавить тестовые данные
        cout << "Добавить тестовые данные? (y/n): ";
        char choice;
        cin >> choice;
        
        if (choice == 'y' || choice == 'Y') {
            file << "Иван Иванов 01.01.2024 15000.50" << endl;
            file << "Петр Петров 15.01.2024 20000.00" << endl;
            file << "Мария Сидорова 20.01.2024 18000.75" << endl;
            cout << "Тестовые данные добавлены!" << endl;
        }
        
        file.close();
    } else {
        cout << "Ошибка создания файла!" << endl;
    }
}

// Функция для чтения файла
void readFile(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "Файл не найден! Создайте его сначала." << endl;
        return;
    }

    vector<Payment> list;
    Payment p;
    
    while (file >> p.name >> p.surname >> p.date >> p.amount) {
        list.push_back(p);
    }
    file.close();

    if (list.empty()) {
        cout << "Файл пустой!" << endl;
    } else {
        cout << "\n=== ВЕДОМОСТЬ ВЫПЛАТ ===\n";
        for (auto& x : list) {
            cout << x.name << " " << x.surname << " | Дата: " << x.date 
                 << " | Сумма: " << x.amount << " руб.\n";
        }
        cout << "=============================\n";
    }
}

// Функция для добавления записи
void addRecord(const string& filePath) {
    ofstream file(filePath, ios::app);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла! Создайте его сначала." << endl;
        return;
    }

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

// Функция для очистки файла
void clearFile(const string& filePath) {
    cout << "Вы уверены, что хотите очистить файл? (y/n): ";
    char choice;
    cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        ofstream file(filePath, ios::trunc);
        file.close();
        cout << "Файл очищен!" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    string filePath = "payments.txt";  // Относительный путь
    int choice;

    do {
        cout << "\n=== УПРАВЛЕНИЕ ФАЙЛОМ ВЫПЛАТ ===\n";
        cout << "1. Создать файл\n";
        cout << "2. Просмотреть данные\n";
        cout << "3. Добавить запись\n";
        cout << "4. Очистить файл\n";
        cout << "5. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createFile(filePath);
                break;
            case 2:
                readFile(filePath);
                break;
            case 3:
                addRecord(filePath);
                break;
            case 4:
                clearFile(filePath);
                break;
            case 5:
                cout << "Выход из программы..." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (choice != 5);

    return 0;
}