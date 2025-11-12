#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Friend {
    string name;
    int year, month, day;
};

int main() {
    setlocale(LC_ALL, "Russian");

    vector<Friend> friends;
    cout << "Введите имя и дату рождения (ГГГГ/ММ/ДД), или end для завершения:\n";

    while (true) {
        Friend f;
        cout << "Имя: ";
        cin >> f.name;
        if (f.name == "end") break;

        char sep;
        cout << "Дата (ГГГГ/ММ/ДД): ";
        cin >> f.year >> sep >> f.month >> sep >> f.day;
        friends.push_back(f);
    }

    if (friends.empty()) {
        cout << "Нет данных о друзьях.\n";
        return 0;
    }

    time_t now = time(nullptr);
    tm today{};
#ifdef _WIN32
    localtime_s(&today, &now);
#else
    localtime_r(&now, &today);
#endif

    bool foundToday = false;
    vector<pair<int, string>> upcoming;

    for (auto& f : friends) {
        tm birthday{};
        birthday.tm_mday = f.day;
        birthday.tm_mon = f.month - 1;
        birthday.tm_year = today.tm_year; // текущий год

        time_t btime = mktime(&birthday);

        if (difftime(btime, now) < 0) {
            birthday.tm_year++; // если уже прошёл — переносим
            btime = mktime(&birthday);
        }

        double diffSec = difftime(btime, now);
        int diffDays = static_cast<int>(diffSec / (60 * 60 * 24));

        if (diffDays == 0) {
            cout << "Сегодня день рождения у: " << f.name << "!\n";
            foundToday = true;
        }
        else {
            upcoming.push_back({ diffDays, f.name });
        }
    }

    if (!foundToday && !upcoming.empty()) {
        sort(upcoming.begin(), upcoming.end());
        cout << "\nБлижайший день рождения через "
            << upcoming.front().first << " дн. у " << upcoming.front().second << "\n";
    }

    return 0;
}