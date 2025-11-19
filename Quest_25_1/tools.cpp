#include "tools.h"
#include <iomanip>

bool operator==(const Point& a, const Point& b) {
    const double EPS = 1e-9;
    return std::abs(a.x - b.x) < EPS && std::abs(a.y - b.y) < EPS;
}

Point readPoint() {
    Point p;
    std::cin >> p.x >> p.y;
    return p;
}

void printPoint(const Point& p) {
    std::cout << std::fixed << std::setprecision(3) << "(" << p.x << ", " << p.y << ")";
}

void scalpel(const Point& p1, const Point& p2) {
    std::cout << "Scalpel: разрез от ";
    printPoint(p1);
    std::cout << " до ";
    printPoint(p2);
    std::cout << std::endl;
}

void hemostat(const Point& p) {
    std::cout << "Hemostat: зажим в ";
    printPoint(p);
    std::cout << std::endl;
}

void tweezers(const Point& p) {
    std::cout << "Tweezers: пинцет в ";
    printPoint(p);
    std::cout << std::endl;
}

void suture(const Point& p1, const Point& p2) {
    std::cout << "Suture: шов от ";
    printPoint(p1);
    std::cout << " до ";
    printPoint(p2);
    std::cout << std::endl;
}