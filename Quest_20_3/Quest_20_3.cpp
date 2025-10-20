#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    string desiredFish, fish;
    int count = 0;

    cout << "Какую рыбу хотите поймать? ";
    cin >> desiredFish;

    ifstream river("C:\\Users\\User\\Desktop\\C\\Test\\Quest\\Quest_20_3\\river.txt");
    ofstream basket("C:\\Users\\User\\Desktop\\C\\Test\\Quest\\Quest_20_3\\basket.txt", ios::app);

    if (!river.is_open() || !basket.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    while (river >> fish) {
        if (fish == desiredFish) {
            basket << fish << endl;
            count++;
        }
    }

    river.close();
    basket.close();

    cout << "Вы поймали " << count << " рыб(ы) " << desiredFish << "!" << endl;
    return 0;
}