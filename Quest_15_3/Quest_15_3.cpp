#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
    int top5[5];     // здесь всегда будут храниться 5 наименьших чисел
    int count = 0;   // сколько чисел реально хранится (до 5)

    cout << "Введите числа. -1 -> вывести 5-е по возрастанию, -2 -> завершить.\n";

    while (true) {
        int x;
        cin >> x;

        if (x == -2) {
            cout << "Завершение программы.\n";
            break;
        }
        else if (x == -1) {
            if (count < 5) {
                cout << "Недостаточно чисел для поиска 5-го минимума\n";
            }
            else {
                cout << "Пятое по возрастанию число = " << top5[4] << endl;
            }
        }
        else {
            // Вставляем число в массив top5 (если нужно)
            if (count < 5) {
                top5[count] = x;
                count++;
                // сортируем вставкой массив top5
                for (int i = 0; i < count; i++) {
                    for (int j = i + 1; j < count; j++) {
                        if (top5[i] > top5[j]) {
                            int tmp = top5[i];
                            top5[i] = top5[j];
                            top5[j] = tmp;
                        }
                    }
                }
            }
            else {
                // если массив уже заполнен
                if (x < top5[4]) { // только если новое число меньше текущего 5-го
                    top5[4] = x;
                    // пересортируем массив
                    for (int i = 0; i < 5; i++) {
                        for (int j = i + 1; j < 5; j++) {
                            if (top5[i] > top5[j]) {
                                int tmp = top5[i];
                                top5[i] = top5[j];
                                top5[j] = tmp;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}