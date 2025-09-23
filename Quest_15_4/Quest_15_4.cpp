#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int a[100];
    cout << "Введите " << n << " чисел (отсортированных по возрастанию):\n";
    for (int i = 0; i < n; i++) cin >> a[i];

    // Два указателя: слева отрицательные, справа положительные
    int right = 0;
    while (right < n && a[right] < 0) right++;
    int left = right - 1;

    cout << "Результат: ";
    while (left >= 0 || right < n) {
        if (left < 0) {
            cout << a[right++] << " ";
        }
        else if (right >= n) {
            cout << a[left--] << " ";
        }
        else {
            if (abs(a[left]) <= abs(a[right])) {
                cout << a[left--] << " ";
            }
            else {
                cout << a[right++] << " ";
            }
        }
    }
    cout << endl;
    return 0;
}
