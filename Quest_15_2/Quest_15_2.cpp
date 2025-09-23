#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int a[100];
    cout << "Введите " << n << " чисел:\n";
    for (int i = 0; i < n; i++) cin >> a[i];

    int target;
    cout << "Введите результат (сумму): ";
    cin >> target;

    // Перебираем все пары чисел
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] + a[j] == target) {
                cout << "Найдены числа: " << a[i] << " и " << a[j] << endl;
                return 0; // нашли — можно завершить
            }
        }
    }

    cout << "Пара не найдена" << endl;
    return 0;
}
