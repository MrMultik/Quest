#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int a[100]; // фиксированный массив (для учебных примеров)
    cout << "Введите " << n << " чисел:\n";
    for (int i = 0; i < n; i++) cin >> a[i];

    int bestSum = -1000000; // заведомо маленькое число
    int bestL = 0, bestR = 0;

    // Два цикла для перебора всех отрезков массива
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum > bestSum) {
                bestSum = sum;
                bestL = i;
                bestR = j;
            }
        }
    }

    cout << "Максимальная сумма = " << bestSum << endl;
    cout << "Индексы: " << bestL << " " << bestR << " (0-based)" << endl;
    return 0;
}
