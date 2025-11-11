#include <iostream>
#include <string>
#include <map>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    map<string, double> tasks;
    string command, currentTask;
    time_t startTime = 0;

    cout << "Введите команду (begin, end, status, exit):\n";

    while (true) {
        cout << "> ";
        cin >> command;

        if (command == "begin") {
            if (!currentTask.empty()) {
                // Завершаем предыдущую задачу
                time_t endTime = time(nullptr);
                tasks[currentTask] += difftime(endTime, startTime) / 3600.0; // часы
                cout << "Задача \"" << currentTask << "\" завершена.\n";
            }
            cout << "Введите название новой задачи: ";
            cin.ignore();
            getline(cin, currentTask);
            startTime = time(nullptr);
            cout << "Задача \"" << currentTask << "\" начата.\n";
        }
        else if (command == "end") {
            if (currentTask.empty()) {
                cout << "Нет активной задачи.\n";
                continue;
            }
            time_t endTime = time(nullptr);
            tasks[currentTask] += difftime(endTime, startTime) / 3600.0;
            cout << "Задача \"" << currentTask << "\" завершена.\n";
            currentTask.clear();
        }
        else if (command == "status") {
            cout << "\n--- Отчёт по задачам ---\n";
            for (auto it = tasks.begin(); it != tasks.end(); ++it) {
                const string& name = it->first;
                double& hours = it->second;
                cout << "• " << name << ": " << hours << " ч.\n";
            }
            if (!currentTask.empty())
                cout << "Текущая задача: " << currentTask << endl;
            cout << "-------------------------\n";
        }
        else if (command == "exit") {
            cout << "Выход из программы.\n";
            break;
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }
    return 0;
}