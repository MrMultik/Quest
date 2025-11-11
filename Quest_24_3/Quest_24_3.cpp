#include <iostream>
#include <iomanip>
#include <ctime>
#include <thread>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int minutes, seconds;
    cout << "Введите время таймера (минуты секунды): ";
    cin >> minutes >> seconds;

    int totalSeconds = minutes * 60 + seconds;

    cout << "Таймер запущен на " << minutes << " мин. " << seconds << " сек.\n";

    while (totalSeconds > 0) {
        int m = totalSeconds / 60;
        int s = totalSeconds % 60;

        cout << "\rОсталось: " << setw(2) << setfill('0') << m << ":"
            << setw(2) << setfill('0') << s << flush;

        this_thread::sleep_for(chrono::seconds(1));
        totalSeconds--;
    }

    cout << "\nDING! DING! DING! Время вышло!\n";
    return 0;
}