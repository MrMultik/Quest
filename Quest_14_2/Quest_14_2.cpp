#include <iostream>
#include <array>
#include <clocale>
#include <limits>
using namespace std;

// Печать игрового поля: '.' обозначает пустую клетку
void printBoard(const array<array<char, 3>, 3>& b) {
    cout << "  1 2 3\n";
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << ' ';
        for (int j = 0; j < 3; ++j) {
            cout << (b[i][j] == ' ' ? '.' : b[i][j]);
            if (j < 2) cout << ' ';
        }
        cout << '\n';
    }
}

// Проверка победы по горизонталям и вертикалям (диагонали по условию не считаем)
bool checkWin(const array<array<char, 3>, 3>& b, char ch) {
    // горизонтали
    for (int i = 0; i < 3; ++i)
        if (b[i][0] == ch && b[i][1] == ch && b[i][2] == ch) return true;
    // вертикали
    for (int j = 0; j < 3; ++j)
        if (b[0][j] == ch && b[1][j] == ch && b[2][j] == ch) return true;
    return false;
}

int main() {
    setlocale(LC_ALL, "");

    // Инициализация поля пробелами (пусто)
    array<array<char, 3>, 3> board;
    for (auto& row : board) row.fill(' ');

    char player = 'X'; // первый игрок X
    int moves = 0;     // количество сделанных ходов

    cout << "Крестики-нолики (3x3). Ввод: row col (1..3)." << endl;
    printBoard(board);

    // Игровой цикл: максимум 9 ходов
    while (moves < 9) {
        int r, c;

        // Цикл ввода для текущего хода:
        // повторяем, пока не получим корректные координаты и пустую клетку
        while (true) {
            cout << "Игрок " << player << ", ваш ход. Введите row col: ";
            if (!(cin >> r >> c)) {
                // неверный ввод (например буквы) — очищаем состояние потока и буфер
                cout << "Неверный ввод. Введите два числа через пробел (например: 2 3)." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            // Проверка диапазона
            if (r < 1 || r > 3 || c < 1 || c > 3) {
                cout << "Координаты вне диапазона 1..3. Попробуйте снова." << endl;
                continue;
            }

            // Переводим в 0-based индексы
            --r; --c;

            // Если клетка занята — сообщаем и остаёмся на том же игроке (не меняем player)
            if (board[r][c] != ' ') {
                cout << "Клетка занята. В ней находится символ: '" << board[r][c] << "'. Выберите другую." << endl;
                continue; // остаёмся в цикле ввода
            }

            // Все проверки пройдены — выполняем ход
            board[r][c] = player;
            ++moves;
            break; // выходим из цикла ввода для текущего хода
        } // конец цикла ввода

        // Печатаем поле после успешного хода
        printBoard(board);

        // Проверяем победу текущего игрока
        if (checkWin(board, player)) {
            cout << "Игрок " << player << " победил!" << endl;
            return 0;
        }

        // Меняем игрока
        player = (player == 'X') ? 'O' : 'X';
    }

    // Если досрочной победы нет — ничья
    cout << "Ничья." << endl;
    return 0;
}
