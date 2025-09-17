#include <iostream>
#include <array>
#include <iomanip>
#include <clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	const int R = 2; // 2 ряда
	const int C = 6; // по 6 мест в ряду -> 12 мест

// Массивы для приборов, тарелок и стульев
array<array<int, C>, R> forks{}; // вилки
array<array<int, C>, R> spoons{}; // обычные ложки
array<array<int, C>, R> knives{}; // ножи
array<array<int, C>, R> dessert_spoons{}; // маленькие десертные ложки для VIP
array<array<int, C>, R> plates{}; // тарелки
array<array<int, C>, R> chairs{}; // стулья


// Инициализация базовых значений: каждому по 1 вилке, 1 ложке, 1 ножу, 2 тарелки, 1 стул
for (int i = 0; i < R; ++i) {
	for (int j = 0; j < C; ++j) {
		forks[i][j] = 1;
		spoons[i][j] = 1;
		knives[i][j] = 1;
		dessert_spoons[i][j] = 0; // десертная ложка только у VIP
		plates[i][j] = 2; // 2 тарелки: первое и второе
		chairs[i][j] = 1;
	}
}


// Выделяем VIP-места: предположим, это первый ряд (0), места 0 и 1
dessert_spoons[0][0] = 1;
dessert_spoons[0][1] = 1;
plates[0][0] += 1; // VIP дополнительная тарелка для десерта
plates[0][1] += 1;


// Сценарий событий:
// 1) Дама на 5-м месте первого ряда привела ребёнка -> добавляем стул
// Индекс: ряд 0, 5-е место -> индекс 4 (0-based)
chairs[0][4] += 1;


// 2) С третьего места второго ряда (ряд 1, индекс 2) была украдена ложка
if (spoons[1][2] > 0) spoons[1][2] -= 1;


// 3) Одна из VIP-персон поделилась своей десертной ложкой с тем, кто остался без ложки
// и стала есть суп десертной. Официант забирает у VIP одну десертную тарелку.
// Проверим, остался ли кто без ложки — это место (1,2)
if (spoons[1][2] == 0) {
	// Попробуем взять десертную ложку у VIP (0,0), если есть
	if (dessert_spoons[0][0] > 0) {
		dessert_spoons[0][0] -= 1; // VIP отдал маленькую ложку
		spoons[1][2] += 1; // получатель получил ложку
		if (plates[0][0] > 0) plates[0][0] -= 1; // официант забрал десертную тарелку
	}
	else if (dessert_spoons[0][1] > 0) {
		// если первая VIP не имела десертной ложки (на всякий случай)
		dessert_spoons[0][1] -= 1;
		spoons[1][2] += 1;
		if (plates[0][1] > 0) plates[0][1] -= 1;
	}
}


// Функция вывода таблицы
auto print_table = [&](const string& title, const auto& arr) {
	cout << title << ":\n";
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << setw(3) << arr[i][j] << (j + 1 == C ? "" : " ");
		}
		cout << "\n";
	}
	cout << "\n";
	};


print_table("Вилки", forks);
print_table("Ложки", spoons);
print_table("Десертные маленькие ложки (VIP)", dessert_spoons);
print_table("Ножи", knives);
print_table("Тарелки", plates);
print_table("Стулья", chairs);


cout << "VIP-места: (0,0) и (0,1). Лишний стул добавлен в (0,4)." << endl;
return 0;
}