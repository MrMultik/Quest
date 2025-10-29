#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <locale>
using namespace std;

struct Player {
    int x, y;
    int hp;
    int attack;
};

struct Enemy {
    int x, y;
    int hp;
    int attack;
    bool alive;
};

const int MAP_SIZE = 20;
string saveFile = "C:\\Users\\User\\Desktop\\C\\Test\\Quest\\Quest_21_5_4\\save.txt";

void drawMap(Player& p, vector<Enemy>& enemies) {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            bool drawn = false;
            if (p.x == x && p.y == y) {
                cout << "P";
                drawn = true;
            }
            else {
                for (auto& e : enemies) {
                    if (e.alive && e.x == x && e.y == y) {
                        cout << "E";
                        drawn = true;
                        break;
                    }
                }
            }
            if (!drawn) cout << ".";
        }
        cout << endl;
    }
}

void saveGame(Player& p, vector<Enemy>& enemies) {
    ofstream file(saveFile);
    if (!file.is_open()) {
        cout << "Ошибка: не удалось сохранить игру!" << endl;
        return;
    }
    file << p.x << " " << p.y << " " << p.hp << " " << p.attack << endl;
    for (auto& e : enemies)
        file << e.x << " " << e.y << " " << e.hp << " " << e.attack << " " << e.alive << endl;
    file.close();
    cout << "Игра успешно сохранена!" << endl;
}

bool loadGame(Player& p, vector<Enemy>& enemies) {
    ifstream file(saveFile);
    if (!file.is_open()) {
        cout << "Сохранение не найдено. Начало новой игры.\n";
        return false;
    }
    file >> p.x >> p.y >> p.hp >> p.attack;
    for (auto& e : enemies)
        file >> e.x >> e.y >> e.hp >> e.attack >> e.alive;
    file.close();
    cout << "Игра успешно загружена!" << endl;
    return true;
}

void fight(Player& p, Enemy& e) {
    cout << "\nНачался бой!" << endl;
    while (p.hp > 0 && e.hp > 0) {
        e.hp -= p.attack;
        cout << "Вы нанесли удар. HP врага: " << e.hp << endl;
        if (e.hp <= 0) {
            e.alive = false;
            cout << "Враг побежден!" << endl;
            return;
        }
        p.hp -= e.attack;
        cout << "Враг атаковал вас! Ваш HP: " << p.hp << endl;
    }
    if (p.hp <= 0)
        cout << "Вы погибли. Игра окончена." << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    Player player{ 10, 10, 100, 20 };
    vector<Enemy> enemies(5);

    // Инициализация врагов
    for (auto& e : enemies) {
        e.x = rand() % MAP_SIZE;
        e.y = rand() % MAP_SIZE;
        e.hp = 50 + rand() % 101;
        e.attack = 10 + rand() % 11;
        e.alive = true;
    }

    cout << "=== Добро пожаловать в RPG 21.5 ===" << endl;
    cout << "Загрузить сохранение? (1 - да, 0 - нет): ";
    int load;
    cin >> load;
    if (load) loadGame(player, enemies);

    char move;
    while (true) {
        cout << "\nВаш HP: " << player.hp << endl;
        drawMap(player, enemies);
        cout << "Управление: W/A/S/D — движение, Q — сохранить, E — выход" << endl;
        cin >> move;

        int newX = player.x, newY = player.y;
        if (move == 'w' || move == 'W') newY--;
        else if (move == 's' || move == 'S') newY++;
        else if (move == 'a' || move == 'A') newX--;
        else if (move == 'd' || move == 'D') newX++;
        else if (move == 'q' || move == 'Q') { saveGame(player, enemies); continue; }
        else if (move == 'e' || move == 'E') { cout << "Выход из игры." << endl; break; }

        if (newX < 0 || newY < 0 || newX >= MAP_SIZE || newY >= MAP_SIZE) {
            cout << "Нельзя выйти за пределы карты!" << endl;
            continue;
        }

        bool fightStarted = false;
        for (auto& e : enemies) {
            if (e.alive && e.x == newX && e.y == newY) {
                fightStarted = true;
                fight(player, e);
                break;
            }
        }

        if (!fightStarted && player.hp > 0) {
            player.x = newX;
            player.y = newY;
        }

        if (player.hp <= 0) {
            cout << "Игра окончена." << endl;
            break;
        }

        bool allDead = true;
        for (auto& e : enemies) if (e.alive) allDead = false;
        if (allDead) {
            cout << "\nПобеда! Все враги уничтожены!" << endl;
            break;
        }
    }
}
