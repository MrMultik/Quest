#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
using namespace std;
using namespace std::chrono;

int main() {
    setlocale(LC_ALL, "Russian");

    int minutes, seconds;
    cout << "Введите время для таймера (минуты секунды): ";
    cin >> minutes >> seconds;

    int totalSeconds = minutes * 60 + seconds;
    auto end = system_clock::now() + std::chrono::seconds(totalSeconds);

    while (system_clock::now() < end) {
        auto remaining = duration_cast<std::chrono::seconds>(end - system_clock::now());
        int m = remaining.count() / 60;
        int s = remaining.count() % 60;
        cout << "\rОсталось: " << setw(2) << setfill('0') << m
            << ":" << setw(2) << setfill('0') << s << flush;
        this_thread::sleep_for(milliseconds(500)); // не нагружаем CPU
    }

    cout << "\nDING! DING! DING!\n";
    return 0;
}