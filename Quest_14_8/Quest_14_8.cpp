#include <iostream>
#include <array>
#include <vector>
#include <clocale>
#include <limits>
using namespace std;

const int N = 10; // размер поля 10x10

using Field = array<array<char, N>, N>;

// Печать поля. Если showShips==false, символы 'S' не показываются (скрыты).
void printField(const Field& f, bool showShips) {
    cout << "   ";
    for (int j = 0; j < N; ++j) cout << j << (j < 10 ? " " : " ");
    cout << "\n";
    for (int i = 0; i < N; ++i) {
        cout << (i < 10 ? " " : "") << i << " ";
        for (int j = 0; j < N; ++j) {
            char ch = f[i][j];
            if (!showShips && ch == 'S') cout << ". ";
            else cout << ch << ' ';
        }
        cout << '\n';
    }
}

// Проверка возможности поставить корабль от (r1,c1) до (r2,c2)
bool canPlace(const Field& f, int r1, int c1, int r2, int c2) {
    // корабль должен быть строго по строке или строго по столбцу
    if (r1 != r2 && c1 != c2) return false;
    int len = max(abs(r2 - r1), abs(c2 - c1)) + 1;
    int dr = (r2 == r1) ? 0 : ((r2 > r1) ? 1 : -1);
    int dc = (c2 == c1) ? 0 : ((c2 > c1) ? 1 : -1);
    int r = r1, c = c1;
    for (int k = 0; k < len; ++k) {
        if (r < 0 || r >= N || c < 0 || c >= N) return false;
        if (f[r][c] != '.') return false; // уже занято
        r += dr; c += dc;
    }
    return true;
}

// Ставим корабль: затираем клетки символом 'S'
void placeShip(Field& f, int r1, int c1, int r2, int c2) {
    int len = max(abs(r2 - r1), abs(c2 - c1)) + 1;
    int dr = (r2 == r1) ? 0 : ((r2 > r1) ? 1 : -1);
    int dc = (c2 == c1) ? 0 : ((c2 > c1) ? 1 : -1);
    int r = r1, c = c1;
    for (int k = 0; k < len; ++k) {
        f[r][c] = 'S';
        r += dr; c += dc;
    }
}

// Процедура расстановки всех кораблей для игрока playerId (1 или 2)
int placeAllShipsInteractive(Field& f, int playerId) {
    cout << "\n--- Расстановка кораблей для игрока " << playerId << " ---\n";
    vector<int> ships;
    // по условию: 4 корабля размера 1, 3 размера 2, 2 размера 3, 1 размера 4
    ships.insert(ships.end(), 4, 1);
    ships.insert(ships.end(), 3, 2);
    ships.insert(ships.end(), 2, 3);
    ships.insert(ships.end(), 1, 4);

    int totalCells = 0;
    for (int L : ships) totalCells += L;

    for (size_t idx = 0; idx < ships.size(); ++idx) {
        int L = ships[idx];
        while (true) {
            cout << "\nТекущее поле игрока " << playerId << " ('.' = пусто, 'S' = ваш корабль):\n";
            printField(f, true);
            if (L == 1) {
                cout << "Введите координаты для корабля длины 1 (row col), 0..9: ";
                int r, c;
                if (!(cin >> r >> c)) {
                    cout << "Неверный ввод. Попробуйте снова.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                if (r < 0 || r >= N || c < 0 || c >= N) {
                    cout << "Координаты вне диапазона. Попробуйте снова.\n";
                    continue;
                }
                if (f[r][c] != '.') {
                    cout << "Точка занята. Попробуйте другую.\n";
                    continue;
                }
                placeShip(f, r, c, r, c);
                break;
            }
            else {
                cout << "Введите координаты начала и конца корабля длины " << L << " (r1 c1 r2 c2), 0..9: ";
                int r1, c1, r2, c2;
                if (!(cin >> r1 >> c1 >> r2 >> c2)) {
                    cout << "Неверный ввод. Попробуйте снова.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                // проверяем длину и ориентацию
                if (!(r1 == r2 || c1 == c2)) {
                    cout << "Корабль должен быть строго горизонтальным или вертикальным. Попробуйте снова.\n";
                    continue;
                }
                int len = max(abs(r2 - r1), abs(c2 - c1)) + 1;
                if (len != L) {
                    cout << "Неверная длина указанного отрезка (ожидается " << L << "). Попробуйте снова.\n";
                    continue;
                }
                if (!canPlace(f, r1, c1, r2, c2)) {
                    cout << "Нельзя разместить корабль в этих клетках (пересечение или выход за границы). Попробуйте снова.\n";
                    continue;
                }
                placeShip(f, r1, c1, r2, c2);
                break;
            }
        } // while размещения конкретного корабля
        cout << "Корабль размещён.\n";
    } // for всех кораблей

    cout << "Готово. Итоговое поле игрока " << playerId << ":\n";
    printField(f, true);

    return totalCells;
}

// Печать поля противника, скрывая корабли (показываем только попадания 'X' и промахи 'o')
void printMasked(const Field& f) {
    cout << "   ";
    for (int j = 0; j < N; ++j) cout << j << ' ';
    cout << '\n';
    for (int i = 0; i < N; ++i) {
        cout << (i < 10 ? " " : "") << i << ' ';
        for (int j = 0; j < N; ++j) {
            char ch = f[i][j];
            if (ch == 'X') cout << 'X' << ' ';
            else if (ch == 'o') cout << 'o' << ' ';
            else cout << '.' << ' ';
        }
        cout << '\n';
    }
}

int main() {
    setlocale(LC_ALL, "");

    // создаём два поля и инициализируем точками '.'
    Field p1, p2;
    for (auto& row : p1) row.fill('.');
    for (auto& row : p2) row.fill('.');

    // Расстановка кораблей вручную для двух игроков
    int total1 = placeAllShipsInteractive(p1, 1);
    cout << "\nПередайте терминал второму игроку и нажмите Enter, когда будете готовы...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка остатка
    cin.get();

    int total2 = placeAllShipsInteractive(p2, 2);
    cout << "\nРасстановка завершена. Начинается игра!\n";

    int rem1 = total1; // оставшиеся клетки у игрока1
    int rem2 = total2; // у игрока2

    int turn = 1; // первый ход игрока 1
    while (true) {
        cout << "\nХод игрока " << turn << ".\n";
        Field& opp = (turn == 1) ? p2 : p1; // поле противника
        // Показываем замаскированное поле противника (чтобы атакующий видел только попадания/промахи)
        cout << "Поле противника (показаны только попадания X и промахи o):\n";
        printMasked(opp);

        int r, c;
        cout << "Введите координаты выстрела (row col) 0..9: ";
        if (!(cin >> r >> c)) {
            cout << "Неверный ввод. Попробуйте снова.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (r < 0 || r >= N || c < 0 || c >= N) {
            cout << "Координаты вне диапазона 0..9. Попробуйте снова.\n";
            continue;
        }
        char& cell = opp[r][c];
        if (cell == 'X' || cell == 'o') {
            cout << "Эта клетка уже обстреляна. Попробуйте другую.\n";
            continue;
        }
        if (cell == 'S') {
            cell = 'X'; // попадание
            cout << "Попадание!\n";
            if (turn == 1) --rem2; else --rem1;
        }
        else {
            cell = 'o'; // промах
            cout << "Мимо.\n";
        }

        // Проверяем окончание игры
        if (rem1 == 0) {
            cout << "Все корабли игрока 1 уничтожены. Игрок 2 победил!\n";
            break;
        }
        if (rem2 == 0) {
            cout << "Все корабли игрока 2 уничтожены. Игрок 1 победил!\n";
            break;
        }

        // Смена хода
        turn = (turn == 1) ? 2 : 1;
    }

    cout << "Игра окончена.\n";
    return 0;
}
