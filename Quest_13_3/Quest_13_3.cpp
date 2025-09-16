#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> db(20);
    int count = 0;      // сколько элементов всего введено
    int index = 0;      // текущая позиция для записи

    while (true) {
        int num;
        cout << "input number: ";
        cin >> num;

        if (num == -1) {
            cout << "output: ";
            int printed = min(count, 20);
            int start = (count >= 20) ? index : 0;

            for (int i = 0; i < printed; ++i) {
                cout << db[(start + i) % 20] << " ";
            }
            cout << endl;
        }
        else {
            db[index] = num;
            index = (index + 1) % 20;
            count++;
        }
    }

    return 0;
}
