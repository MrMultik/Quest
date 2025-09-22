#include <iostream>
#include <vector>
#include <clocale>
#include <limits>
using namespace std;

// Результат: начало, конец, сумма
struct Result {
    int L;
    int R;
    long long sum;
};

// Функция поиска максимального подотрезка (вариант Кадане)
// Возвращает структуру Result с L,R и суммой
Result maxSubarray(const vector<long long>& a) {
    int n = (int)a.size();
    long long bestSum = a[0];
    long long curSum = a[0];
    int bestL = 0, bestR = 0;
    int curL = 0;

    for (int i = 1; i < n; ++i) {
        // Если текущая сумма отрицательна — выгоднее начать заново
        if (curSum < 0) {
            curSum = a[i];
            curL = i;
        }
        else {
            curSum += a[i];
        }

        if (curSum > bestSum) {
            bestSum = curSum;
            bestL = curL;
            bestR = i;
        }
    }
    return { bestL, bestR, bestSum };
}

int main() {
    setlocale(LC_ALL, "");

    cout << "Задача: найти индексы i и j (0-based), для которых сумма a[i]..a[j] максимальна.\n";
    cout << "Введите размер массива (целое > 0): ";

    int n;
    if (!(cin >> n)) {
        cerr << "Ошибка ввода размера.\n";
        return 1;
    }
    if (n <= 0) {
        cerr << "Ошибка: размер массива должен быть положительным.\n";
        return 1;
    }

    vector<long long> a(n);
    cout << "Введите " << n << " целых чисел (через пробел или перевод строки):\n";
    for (int i = 0; i < n; ++i) {
        if (!(cin >> a[i])) {
            cerr << "Ошибка ввода элемента массива.\n";
            return 1;
        }
    }

    Result res = maxSubarray(a);

    cout << "Ответ (индексы 0-based): " << res.L << " " << res.R << "\n";
    cout << "Максимальная сумма = " << res.sum << "\n";

    cout << "Подотрезок: { ";
    for (int i = res.L; i <= res.R; ++i) {
        cout << a[i] << (i < res.R ? ", " : " ");
    }
    cout << "}\n";

    return 0;
}
