#include <iostream>
#include <cmath>
#include <locale>
using namespace std;

struct Vector2D {
    double x;
    double y;
};

Vector2D add(Vector2D a, Vector2D b) { return { a.x + b.x, a.y + b.y }; }
Vector2D subtract(Vector2D a, Vector2D b) { return { a.x - b.x, a.y - b.y }; }
Vector2D scale(Vector2D a, double s) { return { a.x * s, a.y * s }; }
double length(Vector2D a) { return sqrt(a.x * a.x + a.y * a.y); }
Vector2D normalize(Vector2D a) {
    double len = length(a);
    return len == 0 ? a : Vector2D{ a.x / len, a.y / len };
}

int main() {
    setlocale(LC_ALL, "Russian");

    string op;
    cout << "Введите команду (add, subtract, scale, length, normalize): ";
    cin >> op;

    Vector2D a, b;
    if (op == "add" || op == "subtract") {
        cout << "Введите координаты первого вектора (x y): ";
        cin >> a.x >> a.y;
        cout << "Введите координаты второго вектора (x y): ";
        cin >> b.x >> b.y;
        Vector2D result = (op == "add") ? add(a, b) : subtract(a, b);
        cout << "Результат: (" << result.x << ", " << result.y << ")\n";
    }
    else if (op == "scale") {
        double s;
        cout << "Введите координаты вектора (x y): ";
        cin >> a.x >> a.y;
        cout << "Введите скаляр: ";
        cin >> s;
        Vector2D result = scale(a, s);
        cout << "Результат: (" << result.x << ", " << result.y << ")\n";
    }
    else if (op == "length") {
        cout << "Введите координаты вектора (x y): ";
        cin >> a.x >> a.y;
        cout << "Длина: " << length(a) << endl;
    }
    else if (op == "normalize") {
        cout << "Введите координаты вектора (x y): ";
        cin >> a.x >> a.y;
        Vector2D result = normalize(a);
        cout << "Нормализованный вектор: (" << result.x << ", " << result.y << ")\n";
    }
    else cout << "Неизвестная команда.\n";
}
