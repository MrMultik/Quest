#include <iostream>
#include <string>
#include <map>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    map<string, double> tasks;     // Название задачи → часы
    string currentTask;
    time_t startTime = 0;

    string command;
    cout << "Введите команду (begin, end, status, exit):\n";

    while (true) {
        cout << "> ";
        cin >> command;

        if (command == "begin") {
            string name;
            cout << "Введите название задачи: ";
            cin.ignore();
            getline(cin, name);

            // если есть активная — завершаем
            if (!currentTask.empty()) {
                time_t endTime = time(nullptr);
                double hours = difftime(endTime, startTime) / 3600.0;
                tasks[currentTask] += hours;
            }

            currentTask = name;
            startTime = time(nullptr);
            cout << "Начата задача: " << currentTask << "\n";
        }
        else if (command == "end") {
            if (!currentTask.empty()) {
                time_t endTime = time(nullptr);
                double hours = difftime(endTime, startTime) / 3600.0;
                tasks[currentTask] += hours;
                cout << "Завершена задача: " << currentTask << "\n";
                currentTask.clear();
            }
            else {
                cout << "Нет активной задачи.\n";
            }
        }
        else if (command == "status") {
            cout << "\n--- Отчёт по задачам ---\n";
            for (auto& task : tasks)
                cout << "• " << task.first << ": " << task.second << " ч.\n";

            if (!currentTask.empty()) {
                time_t now = time(nullptr);
                double hours = difftime(now, startTime) / 3600.0;
                cout << "\nТекущая задача: " << currentTask
                    << " (" << hours << " ч. сейчас)\n";
            }
            cout << "------------------------\n";
        }
        else if (command == "exit") {
            if (!currentTask.empty()) {
                time_t endTime = time(nullptr);
                tasks[currentTask] += difftime(endTime, startTime) / 3600.0;
            }
            cout << "Выход из программы.\n";
            break;
        }
        else {
            cout << "Неизвестная команда.\n";
        }
    }

    return 0;
}