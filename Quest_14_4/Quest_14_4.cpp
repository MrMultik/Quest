#include <iostream>
#include <array>
#include <iomanip>
#include <clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	array<array<float, 4>, 4> a{}; // матрица 4x4
	array<float, 4> b{}; // вектор 4
	array<float, 4> c{}; // результирующий вектор

	cout << "Введите матрицу a (4x4), построчно (float):\n";
	for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) cin >> a[i][j];

	cout << "Введите вектор b (4 элемента):\n";
	for (int j = 0; j < 4; ++j) cin >> b[j];

	// Вычисляем c = A * b
	for (int i = 0; i < 4; ++i) {
		float acc = 0.0f; // аккумулятор
		for (int j = 0; j < 4; ++j) {
			acc += a[i][j] * b[j];
		}
		c[i] = acc;
	}

	cout << fixed << setprecision(6);
	cout << "Результирующий вектор c:\n";
	for (int i = 0; i < 4; ++i) cout << c[i] << (i == 3 ? "\n" : " ");
	return 0;
}