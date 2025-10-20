#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int width, height;
    cout << "Введите ширину картины: ";
    cin >> width;
    cout << "Введите высоту картины: ";
    cin >> height;

    ofstream pic("C:\\Users\\User\\Desktop\\C\\Test\\Quest\\Quest_20_2\\pic.txt");
    if (!pic.is_open()) {
        cout << "Ошибка создания файла!" << endl;
        return 1;
    }

    srand(time(nullptr));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pic << rand() % 2;
        }
        pic << endl;
    }

    cout << "Картина сохранена в pic.txt!" << endl;
    pic.close();
    return 0;
}