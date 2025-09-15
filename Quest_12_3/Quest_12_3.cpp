#include <iostream>
#include <cassert>
using namespace std;

float travelTime(float distance, float speed) {
    assert(speed > 0); // проверка
    return distance / speed;
}

int main() {
    setlocale(LC_ALL, "");

    float d, s;
    cin >> d >> s;
    cout << "Время в пути: " << travelTime(d, s) << endl;
    return 0;
}