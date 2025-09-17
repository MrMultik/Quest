#include <iostream>
#include <array>
#include <clocale>
#include <limits>
using namespace std;

int main() {
    setlocale(LC_ALL, "");

    const int SIZE = 5;   // размер ландшафта 5x5
    const int MAXH = 10;  // максимальная высота (0..10)

    // Массив высот (SIZE x SIZE)
    array<array<int, SIZE>, SIZE> heights{};

    cout << "Введите матрицу высот " << SIZE << "x" << SIZE << " (целые 0.." << MAXH << "), построчно:\n";

    // Считываем матрицу высот с проверкой ввода
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            while (true) {
                if (!(cin >> heights[i][j])) {
                    cout << "Неверный ввод. Введите целое число (0.." << MAXH << "): ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                if (heights[i][j] < 0) heights[i][j] = 0;
                if (heights[i][j] > MAXH) heights[i][j] = MAXH;
                break;
            }
        }
    }

    cout << "Матрица высот принята.\n";
    cout << "Теперь введите уровень среза (целое L). Программа покажет 1 для клеток, где height >= L, иначе 0.\n";
    cout << "Рекомендуемый диапазон L: 0.." << MAXH << " (введите -1 для выхода).\n";

    while (true) {
        cout << "\nВведите уровень среза L (или -1 для выхода): ";
        int L;
        if (!(cin >> L)) {
            cout << "Неверный ввод. Попробуйте снова.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (L == -1) {
            cout << "Выход.\n";
            break;
        }
        // Проверяем допустимость L (но допускаем и значения за пределами — тогда просто вывод будет соответствующим)
        if (L < 0 || L > MAXH) {
            cout << "Уровень вне типичного диапазона 0.." << MAXH << ". Продолжить (будет использовано условие height >= L)? (y/n): ";
            char ch;
            cin >> ch;
            if (ch != 'y' && ch != 'Y') {
                cout << "Отмена запроса. Введите другой уровень.\n";
                continue;
            }
        }

        // Печатаем срез: 1 если высота >= L, иначе 0
        cout << "Срез для уровня L = " << L << ":\n";
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                cout << (heights[i][j] >= L ? '1' : '0');
                if (j < SIZE - 1) cout << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}