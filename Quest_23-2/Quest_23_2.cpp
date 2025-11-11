#include <iostream>
using namespace std;

// Определите один макрос: SPRING, SUMMER, AUTUMN или WINTER
#define AUTUMN
// #define SPRING
// #define SUMMER
// #define WINTER

int main() {
    setlocale(LC_ALL, "Russian");

#if defined(SPRING)
    cout << "Весна" << endl;
#elif defined(SUMMER)
    cout << "Лето" << endl;
#elif defined(AUTUMN)
    cout << "Осень" << endl;
#elif defined(WINTER)
    cout << "Зима" << endl;
#else
    cout << "Сезон не определён. Определите один из макросов: SPRING, SUMMER, AUTUMN, WINTER." << endl;
#endif

    return 0;
}