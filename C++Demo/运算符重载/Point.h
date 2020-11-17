#pragma once
#include <iostream>
using namespace std;


class Point {
    int m_x;
    int m_y;

public:
    Point(int x, int y);
    Point operator+(const Point &point) const;
    Point operator-(const Point &point) const;
    const Point operator-() const;
    Point &operator+=(const Point &point);
    Point &operator-=(const Point &point);
    bool operator==(const Point &point);
    bool operator!=(const Point &point);
    Point &operator++();
    const Point operator++(int);
}