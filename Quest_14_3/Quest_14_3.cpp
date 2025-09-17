#include <iostream>
#include <array>
#include <clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	array<array<int, 4>, 4> A{};
	array<array<int, 4>, 4> B{};

	cout << "Введите матрицу A (4x4), построчно:\n";
	for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) cin >> A[i][j];

	cout << "Введите матрицу B (4x4), построчно:\n";
	for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) cin >> B[i][j];

	// Сравниваем матрицы поэлементно, при первом различии выходим
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (A[i][j] != B[i][j]) {
				cout << "Матрицы не равны." << endl;
				return 0;
			}
		}
	}

	cout << "Матрицы равны. Привожу матрицу A к диагональной форме...\n";
	// Преобразуем матрицу A: зануляем все элементы вне главной диагонали
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i != j) A[i][j] = 0;
		}
	}

	cout << "Результат (диагональная матрица):\n";
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << A[i][j] << (j == 3 ? "" : " ");
		}
		cout << "\n";
	}
	return 0;
}