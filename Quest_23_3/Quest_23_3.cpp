#include <iostream>
using namespace std;

#define WAGON_COUNT 10
#define MAX_PASSENGERS 20

// Макрос для вызова действия над каждым индексом от 0 до 9
#define FOR_EACH_WAGON(action) \
    action(0)  action(1)  action(2)  action(3)  action(4)  \
    action(5)  action(6)  action(7)  action(8)  action(9)

// Функции анализа (обычные функции)
void analyzeOver(int passengers, int index) {
    if (passengers > MAX_PASSENGERS)
        cout << "Вагон " << index + 1 << " переполнен (" << passengers << " пассажиров)\n";
}
void analyzeUnder(int passengers, int index) {
    if (passengers < MAX_PASSENGERS)
        cout << "Вагон " << index + 1 << " недозаполнен (" << passengers << " пассажиров)\n";
}

int main() {
    setlocale(LC_ALL, "Russian");

    int wagons[WAGON_COUNT];

    cout << "Введите количество пассажиров в каждом из " << WAGON_COUNT << " вагонов:\n";
    for (int i = 0; i < WAGON_COUNT; ++i) {
        cout << "Вагон " << i + 1 << ": ";
        cin >> wagons[i];
    }

    cout << "\n--- Переполненные вагоны ---\n";
#define CALL_OVER(i) analyzeOver(wagons[i], i);
    FOR_EACH_WAGON(CALL_OVER)

        cout << "\n--- Вагоны с пустыми местами ---\n";
#define CALL_UNDER(i) analyzeUnder(wagons[i], i);
    FOR_EACH_WAGON(CALL_UNDER)

        int total = 0;
    for (int i = 0; i < WAGON_COUNT; ++i) total += wagons[i];
    cout << "\nОбщее количество пассажиров: " << total << endl;

    return 0;
}