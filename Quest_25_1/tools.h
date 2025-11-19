#pragma once
#include <iostream>

struct Point {
    double x;
    double y;
};

bool operator==(const Point& a, const Point& b);

Point readPoint();    // читаем точку из std::cin
void printPoint(const Point& p);

void scalpel(const Point& p1, const Point& p2);
void hemostat(const Point& p);
void tweezers(const Point& p);
void suture(const Point& p1, const Point& p2);