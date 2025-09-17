#include <iostream>
#include <array>
#include <clocale>
using namespace std;

// Функция печати пупырки: 'o' - целый пузырёк, 'x' - лопнутый
void printWrap(const array<array<bool, 12>, 12>& w) {
	for (int i = 0; i < 12; ++i) {
		for (int j = 0; j < 12; ++j) {
			cout << (w[i][j] ? 'o' : 'x') << ' ';
		}
		cout << '\n';
	}
}

int main() {
	setlocale(LC_ALL, "");


	array<array<bool, 12>, 12> wrap;
	// Инициализация: все пузырьки целые (true)
	for (auto& row : wrap) row.fill(true);

	int remaining = 12 * 12;

	while (remaining > 0) {
		printWrap(wrap);
		cout << "Введите координаты двух углов прямоугольника: r1 c1 r2 c2 (0..11): ";
		int r1, c1, r2, c2;
		if (!(cin >> r1 >> c1 >> r2 >> c2)) return 0;
		if (r1 < 0 || r1 > 11 || r2 < 0 || r2 > 11 || c1 < 0 || c1 > 11 || c2 < 0 || c2 > 11) {
			cout << "Неверные координаты. Попробуйте снова.\n";
			continue;
		}
		if (r1 > r2) swap(r1, r2);
		if (c1 > c2) swap(c1, c2);

		bool any = false;
		for (int i = r1; i <= r2; ++i) {
			for (int j = c1; j <= c2; ++j) {
				if (wrap[i][j]) {
					wrap[i][j] = false;
					remaining--;
					cout << "Pop!\n";
					any = true;
				}
			}
		}
		if (!any) cout << "В выбранной области нет целых пузырьков.\n";
	}
	cout << "Все пузырьки лопнуты!\n";
	return 0;
}