#include <iostream>
#include <array>
#include <clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	const int N = 5;
	array<array<int, N>, N> a{};
	int num = 0;

	// Заполняем змейкой
	for (int i = 0; i < N; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < N; ++j) a[i][j] = num++;
		}
		else {
			for (int j = N - 1; j >= 0; --j) a[i][j] = num++;
		}
	}

	cout << "Результат заполнения змейкой (5x5):\n";
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) cout << a[i][j] << (j == N - 1 ? "" : " ");
		cout << '\n';
	}
	return 0;
}