#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

struct Friend {
    string name;
    int year = 0, month = 0, day = 0;
};

int main() {
    setlocale(LC_ALL, "Russian");

    vector<Friend> friends;
    string name;
    cout << "Введите имена и даты рождения друзей (год/месяц/день). Введите 'end' для завершения.\n";

    while (true) {
        cout << "Имя: ";
        cin >> name;
        if (name == "end") break;
        Friend f;
        f.name = name;
        cout << "Дата рождения (ГГГГ ММ ДД): ";
        cin >> f.year >> f.month >> f.day;
        friends.push_back(f);
    }

    time_t now = time(nullptr);
    tm current;
    localtime_s(&current, &now);

    int todayMonth = current.tm_mon + 1;
    int todayDay = current.tm_mday;

    bool foundToday = false;
    string nearestName;
    int nearestMonth = 0, nearestDay = 0;
    int minDiff = 400;

    for (auto& f : friends) {
        if (f.month == todayMonth && f.day == todayDay) {
            cout << "Сегодня день рождения у " << f.name << "! [Праздник]\n";
            foundToday = true;
            continue;
        }

        int diff = (f.month - todayMonth) * 31 + (f.day - todayDay);
        if (diff <= 0) diff += 12 * 31; // если день уже прошёл — следующий год
        if (diff < minDiff) {
            minDiff = diff;
            nearestName = f.name;
            nearestMonth = f.month;
            nearestDay = f.day;
        }
    }

    if (!foundToday && !nearestName.empty()) {
        cout << "\nБлижайший день рождения у " << nearestName
            << ": " << nearestMonth << "/" << nearestDay << endl;
    }

    return 0;
}