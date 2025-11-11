#include <iostream>
using namespace std;

// Макросы для дней недели
#define MONDAY "Понедельник"
#define TUESDAY "Вторник"
#define WEDNESDAY "Среда"
#define THURSDAY "Четверг"
#define FRIDAY "Пятница"
#define SATURDAY "Суббота"
#define SUNDAY "Воскресенье"

// Макрос перевода числа в строку (тернарный оператор внутри макроса)
#define DAY_NAME(num) (num == 1 ? MONDAY : \
                      num == 2 ? TUESDAY : \
                      num == 3 ? WEDNESDAY : \
                      num == 4 ? THURSDAY : \
                      num == 5 ? FRIDAY : \
                      num == 6 ? SATURDAY : \
                      num == 7 ? SUNDAY : "Ошибка: некорректный день!")

int main() {
    setlocale(LC_ALL, "Russian");

    int day;
    cout << "Введите номер дня недели (1-7): ";
    cin >> day;
    cout << "Это " << DAY_NAME(day) << endl;
    return 0;
}