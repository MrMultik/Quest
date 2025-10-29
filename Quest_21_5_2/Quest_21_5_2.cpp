#include <iostream>
#include <vector>
#include <string>
#include <locale>
using namespace std;

enum RoomType { bedroom, kitchen, bathroom, children, living };

struct Room {
    RoomType type;
    double area;
};

struct Floor {
    int number;
    double height;
    vector<Room> rooms;
};

struct House {
    int floorsCount;
    vector<Floor> floors;
    bool hasStove;
};

struct Building {
    string type;
    double area;
    bool hasStove;
};

struct LandPlot {
    int id;
    double totalArea;
    vector<Building> buildings;
    House house;
};

int main() {
    setlocale(LC_ALL, "Russian");

    int plotCount;
    cout << "Введите количество участков: ";
    cin >> plotCount;

    vector<LandPlot> village;
    for (int i = 0; i < plotCount; i++) {
        LandPlot plot;
        plot.id = i + 1;

        cout << "\n=== Участок #" << plot.id << " ===\n";
        cout << "Введите общую площадь участка: ";
        cin >> plot.totalArea;

        int buildCount;
        cout << "Введите количество построек: ";
        cin >> buildCount;

        for (int j = 0; j < buildCount; j++) {
            Building b;
            cout << "Тип постройки (дом/гараж/сарай/баня): ";
            cin >> b.type;
            cout << "Площадь постройки: ";
            cin >> b.area;
            b.hasStove = (b.type == "дом" || b.type == "баня");
            plot.buildings.push_back(b);
        }

        cout << "Есть ли жилой дом? (1 - да / 0 - нет): ";
        int has;
        cin >> has;
        if (has) {
            cout << "Количество этажей: ";
            cin >> plot.house.floorsCount;

            for (int f = 0; f < plot.house.floorsCount; f++) {
                Floor floor;
                floor.number = f + 1;
                cout << "Высота потолков этажа #" << floor.number << ": ";
                cin >> floor.height;

                int roomCount;
                cout << "Количество комнат: ";
                cin >> roomCount;
                for (int r = 0; r < roomCount; r++) {
                    Room room;
                    cout << "Введите тип комнаты (1-спальня, 2-кухня, 3-ванная, 4-детская, 5-гостиная): ";
                    int t;
                    cin >> t;
                    room.type = static_cast<RoomType>(t - 1);
                    cout << "Введите площадь комнаты: ";
                    cin >> room.area;
                    floor.rooms.push_back(room);
                }
                plot.house.floors.push_back(floor);
            }
            plot.house.hasStove = true;
        }

        village.push_back(plot);
    }

    cout << "\n=== Итог ===\n";
    for (auto& p : village) {
        double totalBuildings = 0;
        for (auto& b : p.buildings) totalBuildings += b.area;
        cout << "Участок #" << p.id << ": " << (totalBuildings / p.totalArea) * 100 << "% земли занято постройками\n";
    }
}
