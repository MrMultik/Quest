#include <iostream>
using namespace std;

int main() {
    const int SIZE = 15;
    double arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }
    // Простая сортировка выбором (O(n^2))
    for (int i = 0; i < SIZE - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] > arr[maxIndex])
                maxIndex = j;
        }
        // обмен
        double temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }

    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";

    return 0;
}
